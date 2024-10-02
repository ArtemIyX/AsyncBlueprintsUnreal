# Async blueprints nodes plugin for Unreal Engine 5.3
![Nodes](https://github.com/user-attachments/assets/9111c433-b253-4fd7-b24c-3a8b9b7fe5e4)

## Description
Allows you to execute code asynchronously directly in blueprints.

### Async Node
![Async Node](https://github.com/user-attachments/assets/9af521e4-add2-4450-9100-be2823ec325e)

This node allows you to call your blueprint code on another thread. It is suitable for long and short tasks.

> Note, the Callback will be called on the same thread you choose. 

### Async Task Node
![Async Task Node](https://github.com/user-attachments/assets/d0532cfb-266c-4062-b90e-dff3cd27d896)

This node allows you to call your blueprint code on a specific thread. 

It is very useful to return to GameThread and continue working in it.

> Note, the Callback will be called on the same thread you choose. 

## Cautions
- You don't want to use too much of this nodes. It is not a magic wand. Paralleling 10000 array items on a separate threads may be a miserable task for your computer.
- Note that when closing the game at the moment of Async code execution, memory sections that have already been deleted (even if it is just an int variable) may be accessed causing crash.
- It should be noted that most tasks in Unreal Engine can only be executed in Game Thread (Move, Rotate, Spawn Actor etc).

## Documentation
Doxygen documentation: [GitHubPages](https://artemiyx.github.io/AsyncBlueprintsUnrealDoc/index.html)

Documentation sources: [GitHub](https://github.com/ArtemIyX/AsyncBlueprintsUnrealDoc)
