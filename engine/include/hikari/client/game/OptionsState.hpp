#ifndef HIKARI_CLIENT_GAME_OPTIONSSTATE
#define HIKARI_CLIENT_GAME_OPTIONSSTATE

#include "hikari/core/game/GameState.hpp"

#include <memory>
#include <string>

namespace Json {
    class Value;
}

namespace gcn {
    class Container;
    class Label;
    class ActionListener;
    class SelectionListener;
}

namespace hikari {

    namespace gui {
        class Menu;
    }

    class AudioService;
    class GuiService;
    class ServiceLocator;
    class GameController;
    class Input;

    class OptionsState : public GameState {
    private:
        static const std::string AUDIO_LABEL_TEXT;
        static const std::string MUSIC_LABEL_TEXT;
        static const std::string SAMPLE_LABEL_TEXT;

        std::string name;
        GameController & controller;
        std::weak_ptr<GuiService> guiService;
        std::shared_ptr<Input> input;
        std::unique_ptr<gcn::Container> guiContainer;
        std::unique_ptr<gcn::Label> guiLabel;
        std::unique_ptr<gcn::Label> audioLabel;
        std::unique_ptr<gcn::Label> musicLabel;
        std::unique_ptr<gcn::Label> musicVolumeLabel;
        std::unique_ptr<gcn::Label> sampleLabel;
        std::unique_ptr<gcn::Label> sampleVolumeLabel;
        std::unique_ptr<gui::Menu> guiMenu;
        std::unique_ptr<gcn::ActionListener> guiActionListener;
        std::unique_ptr<gcn::SelectionListener> guiSelectionListener;

        bool goToNextState;

        void buildGui();

    public:
        OptionsState(const std::string &name, const Json::Value &params, GameController & controller, ServiceLocator &services);
        virtual ~OptionsState();

        virtual void handleEvent(sf::Event &event);
        virtual void render(sf::RenderTarget &target);
        virtual bool update(float dt);
        virtual void onEnter();
        virtual void onExit();
        virtual const std::string &getName() const;
    };

} // hikari

#endif // HIKARI_CLIENT_GAME_OPTIONSSTATE