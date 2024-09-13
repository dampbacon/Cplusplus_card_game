# Making solatiare (windows xp version) from scratch using C++ and SDL2

## Description:
I've always liked oldschool solitaire from the windows xp days however these days microsoft solitaire exists in a sad state and i've decided to make a minimalistic recreation.
I'm using c plus plus, I wanted to do a proper project using the language as it's commonly used still to this day in many software development areas and I saw value adding it to my repertoire.



### Initial game release:

https://github.com/dampbacon/Cplusplus_card_game/releases/tag/v1

### temp placeholder assets from:
https://60jars.itch.io/card-game-assets

## Game screenshot in current state:
![Sample Image](https://i.imgur.com/8JLAKm1.png)

## Currently in development / next development milestone:
Classic solitaire winscreen

## post mvp goals:
- Classic solitaire winscreen
- Make my own textures
- Create a Linear interpolation pathing system so card being dealt are animated, instead of teleporting.
- Main menu, Widget based ui system.
- Music.
- Scoring.
- Compile to webassembly.
- Polish, allot of polish.
- Make a cmakelists and setup up a cmake buildscript to compile to other platforms.
- May experiment with github actions for ci/cd if i take wasm route.


## Finished features:
All game logic implemented.



## why C++/C ? and not C#, javascript etc.
C++ challenges me a bit more, I'm trying not to stay in my comfort zone too much.

## issues
- Some code is a bit inelegant, needs to be refactored at a later date, was prioritising MVP.
- Some code doesn't follow convention and some has inconsistencies with (low priority, nothing serious)
- For animations and more advanced graphics i'll need to spin off sprites and textures from the game objects (cards) 
