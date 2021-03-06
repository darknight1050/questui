#pragma once
#include <vector>
#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/Component.hpp"

#include "custom-types/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(QuestUI, ExternalComponents, UnityEngine::MonoBehaviour,

    private:
        std::vector<UnityEngine::Component*> components;
    public:
        template<class T = UnityEngine::Component*>
        T Get() {
            return (T)GetByType(csTypeOf(T));
        }

    DECLARE_METHOD(void, Add, UnityEngine::Component* component); 
    DECLARE_METHOD(UnityEngine::Component*, GetByType, Il2CppReflectionType* type); 
    
    DECLARE_OVERRIDE_METHOD(void, Finalize, il2cpp_utils::FindMethod("System", "Object", "Finalize"));

    REGISTER_FUNCTION(ExternalComponents,
        REGISTER_METHOD(Add);
        REGISTER_METHOD(GetByType);
        
        REGISTER_METHOD(Finalize);
    )
)