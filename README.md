### Making solatiare (windows xp version) from scratch using C++ and SDL2

temp placeholder assets from https://60jars.itch.io/card-game-assets

planning to compile to web assembly when the game is playable and host on a website to showcase interactive projects.


## GOALS:
the aim right now is to get a minimum functional game with litle concern to animations and qol features such as a start screen etc.
only a reset button will be added to reset/redeal the game.

## Currently in development / next development milestone:
finishing up the game board, create method to reset all cards to draw pile, game setup and logic.

## post mvp goals:
Make my own textures
Create a Linear interpolation pathing system so card being dealt are animated, instead of teleporting.
Main menu, Widget based ui system.
music.
scoring.
compile to webassembly.
Polish, allot of polish.
make a cmakelists and setup up a cmake buildscript to compile to other platforms.
May experiment with github actions for ci/cd if i take wasm route.


## Finished features:
rendering, texture manager, 160fps game loop, functionality of card stacks and cards. Base functionality in most components done.
Ability to move groups of cards between stacks using your mouse.



## why C++/C ? and not C#, javascript etc.
C++ challenges me a bit more, i'm trying not to stay in my comfort zone too much.

## issues
some code is a bit inelegant, needs to be refactored at a later date, currently prioritising MVP
