### Game Rules

On startup, the game must ask the player to pick a class and a battlefield size. The enemy character must be randomly chosen. Both characters must be randomly assigned a tile in the battlefield, and take turns to try to kill their opponent. The functionality of the program will also be evaluated. Below are some rules that must be followed:

- Each character should only perform one action per turn
    - If they are within range of a target, they must attack. Otherwise, they will move toward the nearest target
    - Your [extra feature](#extra-features) may add some extra actions that can be done in a turn
- The game should work with a battlefield of any size, including a non-square matrix (6x6 or 6x10, for example)
- The game should inform the player when the battle ends, and who was victorious
- The battlefield should only be reprinted/redrawn if there have been any visual changes to it
- Only one character is allowed per tile
- Try to make the program as dynamic as possible
    - Avoid hard-coded rules such as "the player always moves first"

### Extra Features

**Important - Make sure to inform which feature you’re going to work on.

Pick one of the following:

- Every class must implement a "Status Effect" that can be applied to other characters. Examples:
    - "Bleed": Damages the affected target every turn for a limited time
    - "Knock down": Stops the affected target from doing any actions in their next turn
    - "Heal": Heals the affected target
- Every class must implement a "Special Ability" that can be randomly performed. Examples:
    - "Knockback": Knowck the target back one tile
    - "Strong attack": Deals 2x attack damage to a target
    - "Teleport": Teleports the character to any tile
    - "Invisibility": Makes the character "hidden", stopping enemies from chasing or attacking
    - "Throw rock": Character can damage a target from far away
- Instead of only 2 characters, the game must have two opposing teams. The player can still pick their character's class. When a team is completely wiped out, they lose.

(You can add all of them if you want)