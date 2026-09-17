# scripting-the-world
C++ Friend Functions and Classes 

### Scripting the World

Imagine you’re designing a 2D game engine where characters roam, enemies patrol, and power ups trigger hidden effects. At the heart of your engine is the **GameObject**: a class that stores everything a game entity needs to survive: its name, health, position, and animation state.

But there’s a catch. To keep your code clean and well-structured, all this internal data is private. That’s great for encapsulation, but what happens if other parts of your game engine need direct access to this data?

For example, a scripting engine might need to teleport a character across the map. A cutscene tool might want to trigger animations directly. Meanwhile, a debugging system may need to compare game objects or export their data to a file.

Instead of exposing everything publicly (which breaks your class design), you’ll use friend functions and friend classes. These allow you to grant access to internal members, but only to specific, trusted collaborators.

In this project, you’ll build a small but powerful simulation of a real-world game engine. You’ll:

- Create a `GameObject` class with essential properties and behaviors.
    
- Write a `ScriptEngine` class that modifies game objects as a trusted friend.
    
- Add a friend function to compare objects or convert them into strings.
    
- Use operator overloading to improve readability and mimic real game engine behavior.
    

Let’s bring your GameCore engine to life, one object at a time.
1. In this task, you’ll begin creating the core of the `GameObject` class. Inside the class, declare the following members to represent a game entity:

- `string name` – Represents the name or identity of the game object.
- `int health` – Tracks the object’s health or hit points.
- `float x` – Holds the object’s horizontal position in the game world.
- `float y` – Holds the object’s vertical position in the game world.
- `int animationFrame` – Indicates the current animation frame for the object.

1. To allow a game object to be created with all its essential data, add a constructor to the `GameObject` class.
	1. In `GameObject.hpp`, declare a constructor with the following parameters:
	- `string nme` for the object’s name
	- `int hlth` for health
	- `float xpos` and `float ypos` for the x and y position
	- `int frame` for the animation frame
	2. In `GameObject.cpp`, define the constructor using a member initializer list to set the private members.

3. Open `GameObject.hpp` and add a method to simulate the moving characters in a 2D space. We’ll call this method `move`. The `move()` method should take two `float` parameters, `dx` and `dy`, representing how far to move along the x and y axes inside the `GameObject` class.

	Now, open the `GameObject.cpp` and define this method. Inside it, update the object’s position by adding `dx` to `x`, and `dy` to `y`. This will shift the object’s coordinates accordingly.

4. When a character gets hit, their health should go down. To make this possible:

	1. In `GameObject.hpp`, declare a method named `takeDamage()` that will reduce the object’s health when called.
    
	2. The method should:
	    - take a single `int` parameter named `amount` representing the damage
	    - return nothing (`void`)

In the next task, you will define this method in `GameObject.cpp` to subtract the `amount` from the object’s health.

5. Open the `GameObject.cpp` file and define the `takeDamage()` method. Inside the method, subtract the given `amount` from the object’s current `health`. Then print a message showing how much damage was taken and the updated health.

The output should look like this:

```
<Player Name> took <amount> damage. Health now: <health>
```

6. Inside the `GameObject` class in `GameObject.hpp`, declare a public friend class named `ScriptEngine`. This class will control the private state of a game object to simulate actions like teleporting, healing, or advancing animations.

## Implement Friend Functionality and Overloads

7. Open `GameObject.hpp`. Inside the class, declare a friend function that overloads the `==` operator so we can compare two `GameObject` instances by their properties.

The function should take two parameters named `a` and `b`, both of type `const GameObject&`.

8. Open `GameObject.cpp` and define the `friend` function you declared in the previous task to overload the `==` operator for comparing two `GameObject` instances.

This method should return `true` only if:

- The `x` and `y` coordinates of both objects are the same.

9. Game engines often need to save or send a game object’s state as text for example, when saving progress or sending data over a network. To make this possible, we’ll create a helper function.

Open `GameObject.hpp` and declare a friend function named `stringify()`.

- It should take `const GameObject& obj` as a parameter
- It should return a `string`

You’ll write the function body later, for now, only declare it.

10. To save or display a game object’s state, we need a way to convert its data into a single text string. For this, we’ll define the `stringify()` function.

In `main.cpp`, define `stringify(const GameObject& obj)` as declared earlier.

- It should return a `string` containing the object’s internal state.
- Separate each value with `#`.
- The order must be: `name`, `health`, `x`, `y`, `animationFrame`.

Expected Output:

```
Hero#100#0#0#1
```

## Implementing the Position Check

11. In games, a `Position` can represent key spots such as checkpoints, spawn points, or target tiles. To determine if a character is standing on one of these spots, we need a way to compare a `Position` with a `GameObject`.

	Inside the `GameObject` class, declare a friend function that overloads the `==` operator. This will help us compare a `Position` against a `GameObject`.
	
	The function should take:
	
	- a `const Position& pos`
	- a `const GameObject& obj`

12. To check if a `GameObject` is standing on a checkpoint, define the friend `operator==` function in `GameObject.cpp`.

	Inside the function, compare the `x` and `y` values of the `GameObject` with the `x` and `y` values of the `Position`. Return `true` if both match, otherwise return `false`.

## Creating the ScriptEngine Friend Class

13. The `ScriptEngine` class allows external systems to control a `GameObject`. Open the `ScriptEngine.hpp` file and declare the following methods:

- `teleport()`: Move a game object to a new (x, y) position
	- Parameters: `GameObject& obj`, `float newX`, `float newY`
- `heal()`: Increase its health by a given amount
	- Parameters: `GameObject& obj`, `int amount`
- `advanceAnimation()`: Increment the animation frame
	- Parameters: `GameObject& obj`

	These methods will be defined later, and the `GameObject` private state will be modified using friend access. These methods should be static in nature.

14. In `ScriptEngine.cpp`, define the `teleport()` method to update the `x` and `y` members of the given `GameObject`.

After updating the position, print a message in this exact format:

```
[ScriptEngine] Teleported <name> to (<newX>, <newY>)
```

15. Let’s implement the `heal()` method inside the `ScriptEngine.cpp` file. This method allows the `ScriptEngine` to directly increase the `health` of a `GameObject`.

Increase the object’s `health` member inside the method by the specified `amount`. Then, print a message showing the amount healed and the new health value.

Here’s the expected output format:

```
[ScriptEngine] Healed by 20. Health now: 120
```

16.  Let’s finish the scripting engine functionality by implementing the `advanceAnimation()` method. This method should increase the animation frame of the given `GameObject` by `1`, simulating a new animation frame.

Once updated, print a message showing the new animation frame.

Here’s the expected output format to pass the test:

```
[ScriptEngine] Animation frame advanced to: 2
```

## Testing with Game Objects

17. Open `main.cpp` and compare the `posCheck` object with `player1` using the `==` operator.

- If they match, print:
    ```
    Position matches player1's position.Copy to Clipboard
    ```
    
- Otherwise, print:
    ```
    Position does NOT match player1's position.Copy to Clipboard
    ```

18. Let’s simulate an in-game event using the `ScriptEngine` to perform the following actions on `player1`:

	1. Using the `teleport()` function, teleport the player to `(10.0f, 5.0f)`.
	2. Use the `heal()` function to heal the player by 25 points.
	3. Use the `advanceAnimation()` function to move the player’s animation frame forward.

19. Inside `main.cpp`, apply the following steps:

	1. Use the `teleport()` function to move `player2` to `(5.0f, 7.5f)`.
	2. Use the `heal()` method to add 20 health to `player2`.
	3. Use the `advanceAnimation()` to increment the animation frame.

20. Display the full internal state of `player1` using the following two methods:

	1. Call the `stringify()` function and print the returned string using `cout`. Prefix the output with “Stringified player1: “.
	2. Print the object directly using `cout` with the `<<` operator.

	This demonstrates two powerful ways to inspect an object’s internal state.
	
	Here’s the expected Output Format:

	```
	Stringified player1: Hero#100#0#0#2 GameObject(name=Hero, health=100, pos=(0, 0), frame=2)
	```

21. Great job building a basic 2D game engine core! Throughout this process, you explored friend functions, classes, operator overloading, and object encapsulation, which are all key features of C++.

	Want to practice more? Here are some fun challenges to try next:
	
	- Add a function to save GameObject data to a file using `stringify()`
	- Create an `Enemy` class that inherits from `GameObject`, add fields like `attackPower`, `aggroRadius`, and an `attack()` method. (Enemies differ from players by acting automatically and attacking instead of being user-controlled.)
