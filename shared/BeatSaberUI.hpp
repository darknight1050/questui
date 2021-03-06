#pragma once
#include "beatsaber-hook/shared/utils/utils.h"
#include "ArrayUtil.hpp"

#include "CustomTypes/Components/Settings/IncrementSetting.hpp"

#include "GlobalNamespace/MainFlowCoordinator.hpp"
#include "GlobalNamespace/GameplayModifierToggle.hpp"
#include "GlobalNamespace/ColorChangeUIEventType.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/Sprite.hpp"
#include "UnityEngine/UI/Button.hpp"
#include "UnityEngine/UI/Button_ButtonClickedEvent.hpp"
#include "UnityEngine/UI/Image.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/UI/Toggle_ToggleEvent.hpp"
#include "UnityEngine/UI/GridLayoutGroup.hpp"
#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"
#include "UnityEngine/UI/VerticalLayoutGroup.hpp"
#include "UnityEngine/UI/ContentSizeFitter.hpp"
#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/HoverHint.hpp"
#include "HMUI/InputFieldView.hpp"
#include "HMUI/ModalView.hpp"
#include "HMUI/SimpleTextDropdown.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TMP_FontAsset.hpp"
#include "VRUIControls/PhysicsRaycasterWithCache.hpp"

namespace QuestUI::BeatSaberUI {

    GlobalNamespace::MainFlowCoordinator* GetMainFlowCoordinator();

    TMPro::TMP_FontAsset* GetMainTextFont();

    UnityEngine::Sprite* GetEditIcon();

    VRUIControls::PhysicsRaycasterWithCache* GetPhysicsRaycasterWithCache();

    void ClearCache();

    UnityEngine::GameObject* CreateCanvas();

    HMUI::ViewController* CreateViewController(System::Type* type);

    template<class T = HMUI::ViewController*>
    T CreateViewController() {
        return (T)CreateViewController(reinterpret_cast<System::Type*>(csTypeOf(T)));
    }

    HMUI::FlowCoordinator* CreateFlowCoordinator(System::Type* type);

    template<class T = HMUI::FlowCoordinator*>
    T CreateFlowCoordinator() {
        return (T)CreateFlowCoordinator(reinterpret_cast<System::Type*>(csTypeOf(T)));
    }

    TMPro::TextMeshProUGUI* CreateText(UnityEngine::Transform* parent, std::string text, UnityEngine::Vector2 anchoredPosition);

    TMPro::TextMeshProUGUI* CreateText(UnityEngine::Transform* parent, std::string text, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta);
    
    TMPro::TextMeshProUGUI* CreateText(UnityEngine::Transform* parent, std::string text, bool italic = true);

    TMPro::TextMeshProUGUI* CreateText(UnityEngine::Transform* parent, std::string text, bool italic, UnityEngine::Vector2 anchoredPosition);

    TMPro::TextMeshProUGUI* CreateText(UnityEngine::Transform* parent, std::string text, bool italic, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta);

    void SetButtonText(UnityEngine::UI::Button* button, std::string text);

    void SetButtonTextSize(UnityEngine::UI::Button* button, float fontSize);

    void ToggleButtonWordWrapping(UnityEngine::UI::Button* button, bool enableWordWrapping);

    void SetButtonIcon(UnityEngine::UI::Button* button, UnityEngine::Sprite* icon);

    void SetButtonBackground(UnityEngine::UI::Button* button, UnityEngine::Sprite* background);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, std::string buttonTemplate, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, std::string buttonTemplate, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, std::function<void()> onClick);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick);

    UnityEngine::UI::Button* CreateUIButton(UnityEngine::Transform* parent, std::string buttonText, std::string buttonTemplate, std::function<void()> onClick);

    UnityEngine::UI::Image* CreateImage(UnityEngine::Transform* parent, UnityEngine::Sprite* sprite, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta);

    UnityEngine::Sprite* Base64ToSprite(std::string& base64, int width, int height);   

    UnityEngine::Sprite* Base64ToSprite(std::string& base64);   

    UnityEngine::Sprite* FileToSprite(std::string& filePath, int width, int height);

    UnityEngine::Sprite* FileToSprite(std::string& filePath);

    UnityEngine::Sprite* ArrayToSprite(Array<uint8_t>* bytes);

    UnityEngine::UI::GridLayoutGroup* CreateGridLayoutGroup(UnityEngine::Transform* parent);

    UnityEngine::UI::HorizontalLayoutGroup* CreateHorizontalLayoutGroup(UnityEngine::Transform* parent);

    UnityEngine::UI::VerticalLayoutGroup* CreateVerticalLayoutGroup(UnityEngine::Transform* parent);
    
   UnityEngine::UI::Toggle* CreateToggle(UnityEngine::Transform* parent, std::string text, std::function<void(bool)> onToggle);

    UnityEngine::UI::Toggle* CreateToggle(UnityEngine::Transform* parent, std::string text, bool currentValue, std::function<void(bool)> onToggle);
    
    UnityEngine::UI::Toggle* CreateToggle(UnityEngine::Transform* parent, std::string text, UnityEngine::Vector2 anchoredPosition, std::function<void(bool)> onToggle);
    
    UnityEngine::UI::Toggle* CreateToggle(UnityEngine::Transform* parent, std::string text, bool currentValue, UnityEngine::Vector2 anchoredPosition, std::function<void(bool)> onToggle);

    //UnityEngine::GameObject* CreateLoadingIndicator(UnityEngine::Transform* parent, UnityEngine::Vector2 anchoredPosition);

    HMUI::HoverHint* AddHoverHint(UnityEngine::GameObject* gameObject, std::string text);

    QuestUI::IncrementSetting* CreateIncrementSetting(UnityEngine::Transform* parent, std::string text, int decimals, float increment, float currentValue, std::function<void(float)> onValueChange);
    
    QuestUI::IncrementSetting* CreateIncrementSetting(UnityEngine::Transform* parent, std::string text, int decimals, float increment, float currentValue, UnityEngine::Vector2 anchoredPosition, std::function<void(float)> onValueChange);

    QuestUI::IncrementSetting* CreateIncrementSetting(UnityEngine::Transform* parent, std::string text, int decimals, float increment, float currentValue, float minValue, float maxValue, std::function<void(float)> onValueChange);
    
    QuestUI::IncrementSetting* CreateIncrementSetting(UnityEngine::Transform* parent, std::string text, int decimals, float increment, float currentValue, float minValue, float maxValue, UnityEngine::Vector2 anchoredPosition, std::function<void(float)> onValueChange);
    
    QuestUI::IncrementSetting* CreateIncrementSetting(UnityEngine::Transform* parent, std::string text, int decimals, float increment, float currentValue, bool hasMin, bool hasMax, float minValue, float maxValue, UnityEngine::Vector2 anchoredPosition, std::function<void(float)> onValueChange);

    UnityEngine::GameObject* CreateScrollView(UnityEngine::Transform* parent);

    UnityEngine::GameObject* CreateScrollableSettingsContainer(UnityEngine::Transform* parent);

    //HMUI::ModalView* CreateModalView(UnityEngine::Transform* parent);

    HMUI::InputFieldView* CreateStringSetting(UnityEngine::Transform* parent, std::string settingsName, std::string currentValue, std::function<void(std::string)> onValueChange);

    HMUI::InputFieldView* CreateStringSetting(UnityEngine::Transform* parent, std::string settingsName, std::string currentValue, UnityEngine::Vector2 anchoredPosition, std::function<void(std::string)> onValueChange);
 
    HMUI::SimpleTextDropdown* CreateDropdown(UnityEngine::Transform* parent, std::string dropdownName, std::string currentValue, std::vector<std::string> values, std::function<void(std::string)> onValueChange = nullptr);

    //For handleSide, a different int corresponds to each side. 0-left, 1-right, 2-bottom, 3-top, 4-full
    UnityEngine::GameObject* CreateFloatingScreen(UnityEngine::Vector2 screenSize, UnityEngine::Vector3 position, UnityEngine::Vector3 rotation, float curvatureRadius = 0, bool hasBackground = true, bool createHandle = true, int handleSide = 4);
    
    UnityEngine::GameObject* CreateColorPicker(UnityEngine::Transform* parent, std::string text, UnityEngine::Color defaultColor, std::function<void(UnityEngine::Color, GlobalNamespace::ColorChangeUIEventType)> onValueChange = nullptr);

}
