// main.cpp — entry point. Wires config and subsystems together.

#include "livevoicechanger/settings.h"
#include "livevoicechanger/engine.h"
#include "livevoicechanger/io.h"
#include "livevoicechanger/presets.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    livevoicechanger::Settings settings = livevoicechanger::Settings::load_default();
    livevoicechanger::Engine engine(settings.store_path);
    livevoicechanger::Io io(settings.store_path);
    livevoicechanger::Presets presets(settings.store_path);
    std::fprintf(stderr, "[live-voice-changer] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
