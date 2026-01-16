# Making solatiare (windows xp version) from scratch using C++ and SDL2

## 2025 State of project:

 Rewrite now with my better c++ understanding / memory management and use my custom renderer

## 2023 State of project:

## Description:
- I've always liked oldschool solitaire from the windows xp days however these days microsoft solitaire exists in a sad state and i've decided to make a minimalistic recreation.
- I'm using c plus plus, I wanted to do a proper project using the language as it's commonly used still to this day in many software development areas and I saw value adding it to my repertoire.
- In many ways this is a design challenge, I'm not using any frameworks or game engines, this is mostly written by scratch with only a simple library to handle windowing and basic rendering (SDL2)
- I am using C pointers and not shared / unique pointers, I'm using a C Library and it's easier to for me to program in a C style navigating documentation, I'm using only aspects of c++ i find useful such as virtual functions, classes, vector etc. 

### current game release:
https://github.com/dampbacon/Cplusplus_card_game/releases/tag/v4

### temp placeholder card assets from:
https://60jars.itch.io/card-game-assets

### To run:
- download and extract from the link above
- navigate to release folder where extracted
- execute practice.exe

## Game screenshots in current state:
### Classic win screen:
![Sample Image](https://i.imgur.com/w0cthrv.png)
### Initial game state:
![Sample Image](https://i.imgur.com/ORk3Eaa.png)

## Currently in development / next development milestone:
 - polish
 - double click to move card to foundations
 - some custom assets: not the cards yet, I will first prioritise some ui and deck indicator assets
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
- Having a proper tileset will make the game set up much nicer having a loop create all cards rather than having to worry about individual texture names. I'm definitely aware the gameboard set up can be done better but I am holding off till I implement the desired systems and the current state it's in is fine for now, it works.
- some functions need to be spun out and a fair bit of refactoring needs to be done to make the code more elegant, this is not a major priority currently but is something that definitely will be done to clean up the overall design.
- Some code doesn't follow convention and some has inconsistencies with the rest of the overall design(low priority, nothing serious)
- For animations and more advanced graphics to make the code and design overall more elegant i'll need to spin off sprites and textures from the game objects and have the game objects hold that a seperate class. 
