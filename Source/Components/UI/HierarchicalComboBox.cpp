//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBImager and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================

#include "HierarchicalComboBox.h"

//==============================================================================
// CONSTRUCTOR Y DESTRUCTOR
//==============================================================================

HierarchicalComboBox::HierarchicalComboBox()
{
    rootMenu = std::make_unique<MenuItem>();
    rootMenu->text = "Root";
    rootMenu->isCategory = true;
}

HierarchicalComboBox::~HierarchicalComboBox()
{
}

//==============================================================================
// INTERFAZ PÚBLICA EXTENDIDA
//==============================================================================

void HierarchicalComboBox::addCategory(const juce::String& categoryName, 
                                       const juce::StringArray& items, 
                                       int startId)
{
    auto* category = findOrCreateCategory(categoryName);
    
    for (int i = 0; i < items.size(); ++i)
    {
        auto item = std::make_unique<MenuItem>();
        item->text = items[i];
        item->id = startId + i;
        item->isCategory = false;
        item->categoryPath = categoryName;
        
        category->subItems.push_back(std::move(item));
    }
}

void HierarchicalComboBox::addHierarchicalItem(const juce::String& path, int itemId)
{
    auto parts = juce::StringArray::fromTokens(path, "/", "");
    
    if (parts.size() == 0) return;
    
    MenuItem* currentLevel = rootMenu.get();
    juce::String currentPath;
    
    // Navegar/crear categorías hasta el penúltimo elemento
    for (int i = 0; i < parts.size() - 1; ++i)
    {
        if (currentPath.isNotEmpty())
            currentPath += "/";
        currentPath += parts[i];
        
        // Buscar si ya existe esta categoría
        MenuItem* foundCategory = nullptr;
        for (auto& subItem : currentLevel->subItems)
        {
            if (subItem->isCategory && subItem->text == parts[i])
            {
                foundCategory = subItem.get();
                break;
            }
        }
        
        // Si no existe, crearla
        if (!foundCategory)
        {
            auto newCategory = std::make_unique<MenuItem>();
            newCategory->text = parts[i];
            newCategory->isCategory = true;
            newCategory->categoryPath = currentPath;
            
            foundCategory = newCategory.get();
            currentLevel->subItems.push_back(std::move(newCategory));
            categoryMap[currentPath] = foundCategory;
        }
        
        currentLevel = foundCategory;
    }
    
    // Añadir el item final
    auto finalItem = std::make_unique<MenuItem>();
    finalItem->text = parts[parts.size() - 1];
    finalItem->id = itemId;
    finalItem->isCategory = false;
    finalItem->categoryPath = currentPath;
    
    currentLevel->subItems.push_back(std::move(finalItem));
}

void HierarchicalComboBox::clearHierarchy()
{
    clear();  // Limpiar la base CustomComboBox
    rootMenu->subItems.clear();
    categoryMap.clear();
}

void HierarchicalComboBox::rebuildMenu()
{
    clear();  // Limpiar items actuales
    
    int currentId = 1;
    
    // Función recursiva para añadir items al menú plano
    std::function<void(MenuItem*, int)> addItemsRecursive = 
        [&](MenuItem* parent, int depth) 
    {
        for (auto& item : parent->subItems)
        {
            if (item->isSeparator)
            {
                addItem("---", currentId++);
            }
            else if (item->isCategory)
            {
                // Añadir categoría con indicador de flecha
                juce::String prefix;
                for (int i = 0; i < depth; ++i)
                    prefix += "  ";  // Indentación
                    
                addItem(prefix + item->text + " ▶", currentId++);
                
                // Por ahora añadir subitems indentados (luego será submenú)
                addItemsRecursive(item.get(), depth + 1);
            }
            else
            {
                // Item normal
                juce::String prefix;
                for (int i = 0; i < depth; ++i)
                    prefix += "  ";  // Indentación
                    
                addItem(prefix + item->text, item->id);
                currentId++;
            }
        }
    };
    
    // Construir menú desde la raíz
    addItemsRecursive(rootMenu.get(), 0);
}

//==============================================================================
// HELPERS PRIVADOS
//==============================================================================

HierarchicalComboBox::MenuItem* HierarchicalComboBox::findOrCreateCategory(const juce::String& path)
{
    // Si ya existe en el mapa, devolverla
    if (categoryMap.find(path) != categoryMap.end())
        return categoryMap[path];
    
    // Parsear la ruta y crear categorías necesarias
    auto parts = juce::StringArray::fromTokens(path, "/", "");
    MenuItem* currentLevel = rootMenu.get();
    juce::String currentPath;
    
    for (const auto& part : parts)
    {
        if (currentPath.isNotEmpty())
            currentPath += "/";
        currentPath += part;
        
        // Buscar si existe esta subcategoría
        MenuItem* foundCategory = nullptr;
        for (auto& subItem : currentLevel->subItems)
        {
            if (subItem->isCategory && subItem->text == part)
            {
                foundCategory = subItem.get();
                break;
            }
        }
        
        // Si no existe, crearla
        if (!foundCategory)
        {
            auto newCategory = std::make_unique<MenuItem>();
            newCategory->text = part;
            newCategory->isCategory = true;
            newCategory->categoryPath = currentPath;
            
            foundCategory = newCategory.get();
            currentLevel->subItems.push_back(std::move(newCategory));
            categoryMap[currentPath] = foundCategory;
        }
        
        currentLevel = foundCategory;
    }
    
    return currentLevel;
}

void HierarchicalComboBox::addItemToCategory(MenuItem* category, 
                                            const juce::String& itemName, 
                                            int id)
{
    auto item = std::make_unique<MenuItem>();
    item->text = itemName;
    item->id = id;
    item->isCategory = false;
    item->categoryPath = category->categoryPath;
    
    category->subItems.push_back(std::move(item));
}

//==============================================================================
// HIERARCHICAL POPUP WINDOW - Por implementar completamente en siguiente fase
//==============================================================================

HierarchicalComboBox::HierarchicalPopupWindow::HierarchicalPopupWindow(HierarchicalComboBox& owner)
    : comboBox(owner)
{
    // TODO: Implementar ventana popup con soporte para submenús
}

HierarchicalComboBox::HierarchicalPopupWindow::~HierarchicalPopupWindow()
{
}

void HierarchicalComboBox::HierarchicalPopupWindow::paint(juce::Graphics& g)
{
    g.fillAll(DarkTheme::backgroundDark.brighter(0.05f));
    g.setColour(DarkTheme::border);
    g.drawRect(getLocalBounds(), 1);
}

void HierarchicalComboBox::HierarchicalPopupWindow::resized()
{
    viewport.setBounds(getLocalBounds());
}

void HierarchicalComboBox::HierarchicalPopupWindow::mouseMove(const juce::MouseEvent& event)
{
    // TODO: Detectar hover sobre categorías y mostrar submenú
}

void HierarchicalComboBox::HierarchicalPopupWindow::mouseExit(const juce::MouseEvent& event)
{
    // TODO: Ocultar submenú si el mouse sale
}

void HierarchicalComboBox::HierarchicalPopupWindow::showAt(juce::Point<int> position)
{
    setBounds(position.x, position.y, 200, 300);
    setVisible(true);
}

void HierarchicalComboBox::HierarchicalPopupWindow::hideSubMenu()
{
    if (activeSubMenu)
        activeSubMenu->hide();
}

//==============================================================================
// SUBMENU
//==============================================================================

HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::SubMenu(HierarchicalPopupWindow& parent)
{
    juce::ignoreUnused(parent);
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::paint(juce::Graphics& g)
{
    g.fillAll(DarkTheme::backgroundDark.brighter(0.05f));
    g.setColour(DarkTheme::border);
    g.drawRect(getLocalBounds(), 1);
    
    // Dibujar items del submenú
    const int itemHeight = 24;
    int y = 0;
    
    for (size_t i = 0; i < currentItems.size(); ++i)
    {
        auto bounds = juce::Rectangle<int>(0, y, getWidth(), itemHeight);
        
        if (static_cast<int>(i) == hoveredIndex)
        {
            g.setColour(DarkTheme::accent.withAlpha(0.3f));
            g.fillRect(bounds);
        }
        
        g.setColour(DarkTheme::textPrimary);
        g.drawText(currentItems[i]->text, bounds.reduced(10, 0), 
                  juce::Justification::centredLeft, true);
        
        y += itemHeight;
    }
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::mouseDown(const juce::MouseEvent& event)
{
    const int itemHeight = 24;
    int clickedIndex = event.y / itemHeight;
    
    if (clickedIndex >= 0 && clickedIndex < static_cast<int>(currentItems.size()))
    {
        // TODO: Ejecutar callback de selección
    }
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::mouseMove(const juce::MouseEvent& event)
{
    const int itemHeight = 24;
    int newHoveredIndex = event.y / itemHeight;
    
    if (newHoveredIndex != hoveredIndex)
    {
        hoveredIndex = newHoveredIndex;
        repaint();
    }
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::setItems(
    const std::vector<std::unique_ptr<MenuItem>>& items)
{
    currentItems.clear();
    for (const auto& item : items)
    {
        if (!item->isCategory && !item->isSeparator)
            currentItems.push_back(item.get());
    }
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::show(juce::Point<int> position)
{
    setBounds(position.x, position.y, 150, static_cast<int>(currentItems.size()) * 24);
    setVisible(true);
}

void HierarchicalComboBox::HierarchicalPopupWindow::SubMenu::hide()
{
    setVisible(false);
}
