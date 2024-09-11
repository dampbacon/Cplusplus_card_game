# Making solatiare (windows xp version) from scratch using C++ and SDL2
### mvp/initial game release:

https://github.com/dampbacon/Cplusplus_card_game/releases/tag/v1

### temp placeholder assets from:
https://60jars.itch.io/card-game-assets

## Game screenshot in current state:
![Sample Image](https://i.imgur.com/8JLAKm1.png)

## Currently in development / next development milestone:
Classic solitaire winscreen

## post mvp goals:
- classic solitaire winscreen
- Make my own textures
- Create a Linear interpolation pathing system so card being dealt are animated, instead of teleporting.
- Main menu, Widget based ui system.
- music.
- scoring.
- compile to webassembly.
- Polish, allot of polish.
- make a cmakelists and setup up a cmake buildscript to compile to other platforms.
- May experiment with github actions for ci/cd if i take wasm route.


## Finished features:
All game logic implemented.



## why C++/C ? and not C#, javascript etc.
C++ challenges me a bit more, I'm trying not to stay in my comfort zone too much.

## issues
some code is a bit inelegant, needs to be refactored at a later date, was prioritising MVP.
For animations and more advanced graphics i'll need to spin off sprites and textures from the game objects (cards) 
