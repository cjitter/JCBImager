# ==============================================================================
#
#  Copyright 2025 Juan Carlos Blancas
#
#  JCBImager is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  JCBImager is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with JCBImager. If not, see <http://www.gnu.org/licenses/>.
#
# ==============================================================================

cmake_minimum_required(VERSION 3.20)

project(JCBImager VERSION 1.0.0)

# Configuración C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Versión mínima de macOS
set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0" CACHE STRING "Versión mínima de macOS")

# Binary Universal (Apple Silicon + Intel)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Arquitecturas de compilación para macOS")

# Configurar ruta para módulos CMake personalizados (por ejemplo, Pluginval.cmake)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(FetchContent)
FetchContent_Declare(
        JUCE
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG 8.0.8
)
# Opciones de JUCE para evitar compilar extras innecesarios
set(JUCE_BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(JUCE_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(JUCE)

# Opciones de configuración
option(JUCE_BUILD_AAX "Build AAX format (requires AAX SDK and Pro Tools Developer)" ON)
option(JUCE_AUTO_INSTALL_PLUGINS "Auto-install plugins after build" ON)

# SDK externo opcional (AAX) para macOS
set(JUCE_AAX_SDK_PATH "$ENV{HOME}/SDK/aax-sdk-2-8-1" CACHE PATH "Ruta al SDK de AAX")

# Definir los formatos soportados según el estado del flag
if(JUCE_BUILD_AAX)
    set(PLUGIN_FORMATS VST3 AU AAX)
else()
    set(PLUGIN_FORMATS VST3 AU)
endif()

# Crear el plugin usando la lista explícita
juce_add_plugin(JCBImager
        # Información básica del plugin
        PLUGIN_NAME "JCBImager"
        PRODUCT_NAME "JCBImager"
        VERSION 1.0.0
        DESCRIPTION "Multiband stereo imaging processor"

        # Información de la empresa
        COMPANY_NAME "Coeval"
        COMPANY_WEBSITE "https://github.com/cjitter"
        BUNDLE_ID "com.coeval.JCBImager"
        PLUGIN_MANUFACTURER_CODE "CoeV"
        PLUGIN_CODE "CoE7"

        # Formatos soportados
        FORMATS ${PLUGIN_FORMATS}

        # Configuración del plugin
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS TRUE
        COPY_PLUGIN_AFTER_BUILD FALSE

        # Categorías por formato
        VST3_CATEGORIES Spatial
        AU_MAIN_TYPE kAudioUnitType_Effect
        # AU_SUBTYPE puede omitirse para usar el código del plugin
        AAX_CATEGORY AAX_ePlugInCategory_SoundField
)

# Archivos fuente del plugin
target_sources(JCBImager PRIVATE
        # Core plugin files
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp

        # Shared UI components (scaffolded for migration)
        Source/Components/UI/CustomComboBox.cpp
        Source/Components/UI/GoniometerComponent.cpp
        Source/Components/UI/SpectrumAnalyzerComponent.cpp

        # Windows/overlays
        Source/Components/Windows/CreditsWindow.cpp

        # Gen~ DSP engine
        exported-code/JCBImager.cpp
        exported-code/gen_dsp/genlib.cpp
        exported-code/gen_dsp/json.c
        exported-code/gen_dsp/json_builder.c
)

# Añadir recursos binarios (imágenes)
juce_add_binary_data(JCBImager_BinaryData
        SOURCES
        Assets/bypass.png
        Assets/fondo.png
        Assets/diagram.png
        Assets/diagramaFondo.png
        Assets/FactoryPresets/Basic_openMids.preset
)

# Linkear binary data al plugin
target_link_libraries(JCBImager PRIVATE
        JCBImager_BinaryData
)

# Includes
target_include_directories(JCBImager PRIVATE
        Source/
        exported-code/
        exported-code/gen_dsp/
)

# Módulos JUCE
target_link_libraries(JCBImager PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_core
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
)

# Definiciones del compilador - Esenciales + optimizaciones
target_compile_definitions(JCBImager PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_REPORT_APP_USAGE=0
        JUCE_STRICT_REFCOUNTEDPTR=1
)

# Flags del compilador para macOS (Clang)
target_compile_options(JCBImager PRIVATE
        -Wall -Wextra -Wno-unused-parameter
)

option(JCB_DISABLE_SANITIZER "Disable runtime output sanitizer (only when debugging issues)" OFF)
if(JCB_DISABLE_SANITIZER)
    target_compile_definitions(JCBImager PRIVATE JCB_DISABLE_SANITIZER=1)
endif()

# Testing con pluginval (opcional). Requiere cmake/Pluginval.cmake
enable_testing()
include(Pluginval OPTIONAL)

if(COMMAND add_pluginval_build_fixture)
    add_pluginval_build_fixture(JCBImager_VST3)
    add_pluginval_tests(JCBImager_VST3)
    if(TARGET JCBImager_AU)
        add_pluginval_build_fixture(JCBImager_AU)
        add_pluginval_tests(JCBImager_AU)
    endif()
endif()

# Instalación automática para macOS (se puede desactivar con JUCE_AUTO_INSTALL_PLUGINS OFF)
if(JUCE_AUTO_INSTALL_PLUGINS)
    # Do not auto-install on Debug builds to avoid polluting user folders during development
    #if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(FALSE) # Permitir instalación en Debug también
        message(STATUS "Auto-install skipped: Debug configuration")
    else()
    # Rutas de instalación del sistema macOS
    set(VST3_DIR "$ENV{HOME}/Library/Audio/Plug-Ins/VST3")
    set(AU_DIR   "$ENV{HOME}/Library/Audio/Plug-Ins/Components")
    set(AAX_DIR  "/Applications/Pro Tools Developer/Plug-Ins")

    # Instalación VST3 (carpeta de usuario)
    if(TARGET JCBImager_VST3)
        add_custom_command(TARGET JCBImager_VST3 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Installing VST3 to user directory (${VST3_DIR})..."
            COMMAND ${CMAKE_COMMAND} -E make_directory "${VST3_DIR}"
            COMMAND ${CMAKE_COMMAND} -E remove_directory "${VST3_DIR}/JCBImager.vst3"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_BINARY_DIR}/JCBImager_artefacts/$<CONFIG>/VST3/JCBImager.vst3"
                "${VST3_DIR}/JCBImager.vst3"
            COMMENT "Installing VST3 plugin to ${VST3_DIR} (user folder)"
            VERBATIM
        )
    endif()

    # Instalación AU (carpeta de usuario)
    if(TARGET JCBImager_AU)
        add_custom_command(TARGET JCBImager_AU POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Installing AU to user directory (${AU_DIR})..."
            COMMAND ${CMAKE_COMMAND} -E make_directory "${AU_DIR}"
            COMMAND ${CMAKE_COMMAND} -E remove_directory "${AU_DIR}/JCBImager.component"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_BINARY_DIR}/JCBImager_artefacts/$<CONFIG>/AU/JCBImager.component"
                "${AU_DIR}/JCBImager.component"
            COMMENT "Installing AU plugin to ${AU_DIR} (user folder)"
            VERBATIM
        )
    endif()

    # Instalación AAX
    if(TARGET JCBImager_AAX)
        add_custom_command(TARGET JCBImager_AAX POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Installing AAX to AAX_DIR..."
            COMMAND ${CMAKE_COMMAND} -E remove_directory "${AAX_DIR}/JCBImager.aaxplugin"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_BINARY_DIR}/JCBImager_artefacts/$<CONFIG>/AAX/JCBImager.aaxplugin"
                "${AAX_DIR}/JCBImager.aaxplugin"
            COMMENT "Installing AAX plugin to ${AAX_DIR}..."
            VERBATIM
        )
    endif()
    endif()
endif()

# Información de configuración
message(STATUS "JCBImager ${PROJECT_VERSION} - Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build directory: ${CMAKE_CURRENT_BINARY_DIR}/JCBImager_artefacts/")

# Estado del SDK AAX
if(JUCE_BUILD_AAX)
    if(EXISTS "${JUCE_AAX_SDK_PATH}")
        message(STATUS "AAX SDK: Found at ${JUCE_AAX_SDK_PATH}")
        message(STATUS "AAX: Will be built")
    else()
        message(WARNING "AAX SDK not found at ${JUCE_AAX_SDK_PATH} - AAX format disabled")
        message(STATUS "To build AAX, set JUCE_AAX_SDK_PATH to your AAX SDK location")
    endif()
else()
    message(STATUS "AAX: Disabled (use -DJUCE_BUILD_AAX=ON to enable)")
endif()

# Estado de auto-instalación
if(JUCE_AUTO_INSTALL_PLUGINS)
    message(STATUS "Auto-install: Enabled")
else()
    message(STATUS "Auto-install: Disabled")
endif()
