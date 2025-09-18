//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBImager and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================
#pragma once

#include "CustomComboBox.h"
#include <map>
#include <vector>

//==============================================================================
// HIERARCHICAL COMBOBOX - ComboBox con soporte para submenús jerárquicos
//==============================================================================

class HierarchicalComboBox : public CustomComboBox
{
public:
    //==========================================================================
    // TIPOS Y ESTRUCTURAS
    //==========================================================================
    
    struct MenuItem
    {
        juce::String text;
        int id;
        bool isCategory;
        bool isSeparator;
        juce::String categoryPath;  // e.g., "Factory/Drums"
        std::vector<std::unique_ptr<MenuItem>> subItems;
        
        MenuItem() : id(0), isCategory(false), isSeparator(false) {}
    };
    
    //==========================================================================
    // CONSTRUCTOR Y DESTRUCTOR
    //==========================================================================
    
    HierarchicalComboBox();
    ~HierarchicalComboBox() override;
    
    //==========================================================================
    // INTERFAZ PÚBLICA EXTENDIDA
    //==========================================================================
    
    // Añadir categoría con subítems
    void addCategory(const juce::String& categoryName, const juce::StringArray& items, int startId);
    
    // Añadir item con ruta de categoría (e.g., "Factory/Drums/Kick")
    void addHierarchicalItem(const juce::String& path, int itemId);
    
    // Limpiar todo incluyendo jerarquía
    void clearHierarchy();
    
    // Reconstruir menú desde estructura jerárquica
    void rebuildMenu();
    
    //==========================================================================
    // POPUP WINDOW EXTENDIDA PARA SUBMENÚS
    //==========================================================================
    
    class HierarchicalPopupWindow : public juce::Component
    {
    public:
        HierarchicalPopupWindow(HierarchicalComboBox& owner);
        ~HierarchicalPopupWindow() override;
        
        void paint(juce::Graphics& g) override;
        void resized() override;
        void mouseMove(const juce::MouseEvent& event) override;
        void mouseExit(const juce::MouseEvent& event) override;
        
        void showAt(juce::Point<int> position);
        void hideSubMenu();
        
    private:
        //======================================================================
        // SUBMENU COMPONENT
        //======================================================================
        
        class SubMenu : public juce::Component
        {
        public:
            SubMenu(HierarchicalPopupWindow& parent);
            
            void paint(juce::Graphics& g) override;
            void mouseDown(const juce::MouseEvent& event) override;
            void mouseMove(const juce::MouseEvent& event) override;
            
            void setItems(const std::vector<std::unique_ptr<MenuItem>>& items);
            void show(juce::Point<int> position);
            void hide();
            
        private:
            // (reservado) referencia al padre si se necesitase en el futuro
            std::vector<const MenuItem*> currentItems;
            int hoveredIndex = -1;
            
            JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SubMenu)
        };
        
        HierarchicalComboBox& comboBox;
        juce::Viewport viewport;
        std::unique_ptr<juce::Component> listContainer;
        std::unique_ptr<SubMenu> activeSubMenu;
        int hoveredCategoryIndex = -1;
        
        void showSubMenuForCategory(int categoryIndex);
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HierarchicalPopupWindow)
    };
    
private:
    //==========================================================================
    // DATOS PRIVADOS
    //==========================================================================
    
    std::unique_ptr<MenuItem> rootMenu;
    std::map<juce::String, MenuItem*> categoryMap;
    std::unique_ptr<HierarchicalPopupWindow> hierarchicalPopup;
    
    // Helpers para navegación de jerarquía
    MenuItem* findOrCreateCategory(const juce::String& path);
    void addItemToCategory(MenuItem* category, const juce::String& itemName, int id);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HierarchicalComboBox)
};
