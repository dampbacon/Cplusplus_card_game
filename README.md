# Making solatiare (windows xp version) from scratch using C++ and SDL2

## Description:
- I've always liked oldschool solitaire from the windows xp days however these days microsoft solitaire exists in a sad state and i've decided to make a minimalistic recreation.
- I'm using c plus plus, I wanted to do a proper project using the language as it's commonly used still to this day in many software development areas and I saw value adding it to my repertoire.
- In many ways this is a design challenge, I'm not using any frameworks or game engines, this is mostly written by scratch with only a simple library to handle windowing and basic rendering (SDL2)


### current game release:
https://github.com/dampbacon/Cplusplus_card_game/releases/tag/v3

### temp placeholder card assets from:
https://60jars.itch.io/card-game-assets

### To run:
- download and extract from the link above
- navigate to release folder where extracted
- execute practice.exe

## Game screenshots in current state:
### Classic win screen:
![Sample Image](https://i.imgur.com/o2tZxld.png)
### Initial game state:
![Sample Image](https://i.imgur.com/qEZTkVo.png)

## Currently in development / next development milestone:
 - polish (lock end stack cards allowed)
 - some custom assets: not the cards yet, I will first prioritise the red card stack markers
 - prompt for autosolve (currently executes as soon all cards are revealed)


## post mvp goals:
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
Classic solitaire winscreen implemented


## why C++/C ? and not C#, javascript etc.
C++ challenges me a bit more, I'm trying not to stay in my comfort zone too much.

## issues
- Some code is a bit inelegant, needs to be refactored at a later date, was prioritising MVP.
- Some code doesn't follow convention and some has inconsistencies with (low priority, nothing serious)
- For animations and more advanced graphics i'll need to spin off sprites and textures from the game objects (cards) 
