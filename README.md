#Package-Management-System


# Package Management System

A simple Package Management System in C that uses stacks and queues to manage processed and pending packages.

## Features
- **Add Package**: Add a new package to the pending queue.
- **Process Package**: Move a package from the pending queue to the processed stack.
- **View Pending Packages**: Display all packages in the pending queue.
- **View Processed Packages**: Display all packages in the processed stack.

## Data Structures
- **Queue**: Used for managing pending packages.
- **Stack**: Used for managing processed packages.

## How to Use

### Menu Options
1. **Add Package**: Adds a new package to the pending queue.
2. **Process Package**: Moves the first package from the pending queue to the processed stack.
3. **View Pending Packages**: Displays all packages currently in the pending queue.
4. **View Processed Packages**: Displays all packages currently in the processed stack.
5. **Exit**: Exits the program.
```markdown
### Example Usage

Package Management System

Menu:
1. Add Package
2. Process Package
3. View Pending Packages
4. View Processed Packages
5. Exit
Enter your choice: 1
Enter package description: Package A
Package 'Package A' added to the pending packages queue.

Menu:
1. Add Package
2. Process Package
3. View Pending Packages
4. View Processed Packages
5. Exit
Enter your choice: 2
Package 'Package A' removed from the pending packages queue.
Package 'Package A' added to the processed packages stack.

Menu:
1. Add Package
2. Process Package
3. View Pending Packages
4. View Processed Packages
5. Exit
Enter your choice: 3
Pending packages:
No pending packages.

Menu:
1. Add Package
2. Process Package
3. View Pending Packages
4. View Processed Packages
5. Exit
Enter your choice: 4
Processed packages:
- Package A
```

## Code Overview

### Structures
- **struct package**: Represents a package.
- **struct stack**: Stack structure to manage processed packages.
- **struct queue**: Queue structure to manage pending packages.

### Functions
- **initStack**: Initializes the stack.
- **push**: Pushes a package onto the stack.
- **pop**: Pops a package from the stack.
- **displayStack**: Displays all packages in the stack.
- **initQueue**: Initializes the queue.
- **enqueue**: Enqueues a package into the queue.
- **dequeue**: Dequeues a package from the queue.
- **displayQueue**: Displays all packages in the queue.


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
