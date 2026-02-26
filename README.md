# Cub3D 🕹️
*This project was created as part of the [42](https://www.42sp.org.br/) curriculum by `fsousa` and `mhidani`.*

## Description 📃

**Cub3D** is a graphics project from 42 École inspired by the classic game Wolfenstein 3D, which popularized the raycasting technique to simulate a 3D environment using a 2D map. The project focuses on understanding how early game engines worked, reproducing the illusion of depth by casting rays from the player’s perspective and rendering walls, textures, and colors accordingly.

In this project, we build a lightweight rendering engine in C, handling window management, input, textures, and basic game logic without relying on high-level graphics libraries. The main goal is to strengthen low-level programming skills, memory management, and understanding of computer graphics fundamentals.

Cub3D is also a team-based project, requiring collaboration, task distribution, and communication between partners, which makes it an excellent opportunity to practice teamwork and software engineering practices in a real-world-like environment.

## Features
- Ray Casting rendering engine
- Reader and parser of maps in .cub format
- Player movement
- Mini-map showing the player's direction
- Collision between player and walls
- Window management
  - Close button and escape key to close window
  - Button minimize window

_**Cub3D Map: alley.cub**_<br>
<img width="598" height="372" alt="Screenshot from 2026-02-26 07-45-31" src="https://github.com/user-attachments/assets/e50a295e-2b51-46f6-897b-6feef922e360" />

_**Cub3D Map: cube.cub**_<br>
<img width="598" height="372" alt="Screenshot from 2026-02-26 07-45-50" src="https://github.com/user-attachments/assets/987f65d0-16a4-4f40-a8b5-66eefd0fd688" />

_**Cub3D Map: forty_two_school.cub**_<br>
<img width="598" height="372" alt="Screenshot from 2026-02-26 07-56-33" src="https://github.com/user-attachments/assets/e1c8855f-4006-4ee0-a7b7-19c822014d6f" />

## Instructions ⚙️
To run the game, you must always specify a map so that it can be loaded.

If no map is specified, an error message will be displayed.

To run the game, use this command in your `shell`:
```shell
./bin/cub3d ./assets/maps/nuke.cub
```

### How to play
Instructions for playing:
- [**W**] _Move forward_
- [**A**] _Move left_
- [**S**] _Move backward_
- [**D**] _Move right_
- [**Left Arrow**] _Rotate view to the left_
- [**Right Arrow**] _Rotate view to the right_

## Resources 🔍
- [Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [Raycasting Engine](https://www.youtube.com/watch?v=J5K8qMCB-7o&list=PLLFRf_pkM7b6rBRoTOW64NKdltCLQNpW5)
- [Wall Textures](https://itch.io/)

**Find us**:
- Filipe Sousa: fsousa | [linkedin](https://www.linkedin.com/in/filipezzo/)
- Mauricio Hidani: mhidani | [linkedin](https://www.linkedin.com/in/mauricio-hidani/)
