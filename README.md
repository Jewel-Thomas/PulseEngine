# PulseEngine

PulseEngine is a modern C++17 game engine for exploring real-time rendering, layered engine architecture, and performance-oriented systems. It ships as a static library with a **Sandbox** sample app that opens a window, renders geometry, and hosts an ImGui overlay.

> **Platform:** Windows x64 only for now · **Graphics:** OpenGL

---

## Features

- **Application & layers** — singleton app loop, `Layer` / `LayerStack`, overlays for UI
- **Events** — blocking dispatcher for window, keyboard, and mouse events
- **Window & input** — GLFW-backed window (default 1280×720, VSync), polled input API
- **Logging & asserts** — spdlog core/client loggers; debug asserts and `PLS_*` macros
- **ImGui** — docking, multi-viewport, OpenGL3 backend
- **Renderer** — API-agnostic interfaces with an OpenGL backend: clear, indexed draw, VAO/VBO/IBO, buffer layouts, GLSL shaders from source strings
- **Math** — glm

---

## Architecture

```
Pulse/          Static engine library
Sandbox/        Example client application
vendor/         Bundled Premake binary
```

The engine follows a layered design: `Application` owns the main loop and routes events through a `LayerStack`. Rendering goes through `Renderer` → `RenderCommand` → `RendererAPI`, with platform factories creating OpenGL implementations on Windows.

Clients include the public umbrella header `Pulse.h` and implement `Pulse::CreateApplication()`. Entry is provided by `Pulse/EntryPoint.h`.

---

## Requirements

- Windows 10/11 (x64)
- Visual Studio 2019 or newer (Premake generates VS2019 projects)
- Git (with submodule support)

Premake 5 is bundled at `vendor/bin/premake/premake5.exe` — no separate install needed.

---

## Getting started

### Clone

```bash
git clone --recursive https://github.com/Jewel-Thomas/PulseEngine.git
cd PulseEngine
```

If you already cloned without submodules:

```bash
git submodule update --init --recursive
```

### Generate Visual Studio projects

```bat
GenerateProjects.bat
```

This runs Premake and produces `Pulse.sln`. Re-run after changing `premake5.lua`.

### Build & run

1. Open `Pulse.sln` in Visual Studio
2. Set **Sandbox** as the startup project (default)
3. Choose **Debug**, **Release**, or **Dist**
4. Build and run

Binaries land in `bin/{Config}-windows-x86_64/{Pulse|Sandbox}/`.

| Configuration | Notes |
|---------------|--------|
| **Debug** | Symbols, asserts, logging macros active |
| **Release** | Optimized; logging macros no-op |
| **Dist** | Distribution build |

---

## Creating an application

```cpp
#include <Pulse.h>
#include "Pulse/EntryPoint.h"

class MyApp : public Pulse::Application
{
public:
	MyApp()
	{
		// PushLayer(new MyLayer());
	}
};

Pulse::Application* Pulse::CreateApplication()
{
	return new MyApp();
}
```

Link against the **Pulse** static library and include `Pulse/src` (plus vendors as needed). See `Sandbox/` for a working example that draws a colored quad and triangle via `RenderLayer`.

---

## Project layout

```
Pulse/
├── src/
│   ├── Pulse.h                 # Public API for client apps
│   ├── plspch.h / .cpp         # Precompiled headers
│   └── Pulse/
│       ├── Application, Layer, LayerStack, Window, Input, Logger
│       ├── Events/             # Event types & dispatcher
│       ├── Imgui/              # ImGui layer
│       ├── Renderer/           # API-agnostic render interfaces
│       └── Platform/
│           ├── Windows/        # Window & input
│           └── OpenGL/         # Buffers, VAO, shaders, context
│   └── vendor/                 # GLFW, Glad, imgui, glm, spdlog
Sandbox/
└── src/                        # SandboxApp, RenderLayer
```

---

## Dependencies

| Library | Role |
|---------|------|
| [GLFW](https://www.glfw.org/) | Windowing & input |
| [Glad](https://glad.dav1d.de/) | OpenGL loader |
| [Dear ImGui](https://github.com/ocornut/imgui) | Debug / editor UI (docking branch) |
| [glm](https://github.com/g-truc/glm) | Math |
| [spdlog](https://github.com/gabime/spdlog) | Logging |

Most vendors are Git submodules under `Pulse/vendor/`. Glad is vendored in-tree.

---

## License

Licensed under the [Apache License 2.0](LICENSE). Third-party libraries retain their own licenses under their respective directories.
