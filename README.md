# Grade Calculator

A command-line program written in C that tracks class grades and calculates your GPA.

## Features

- Add and delete classes
- Add grades to specific topics within a class
- Calculate your overall GPA on a 4.0 scale

## How It Works

Classes are stored as `.txt` files in a `./Classes/` directory. Each file contains the credit hours, graded topics with their weights, and grades for each topic.

### File Format
```
<credit hours>
<number of topics>
#<TopicName> <weight>
...
Grades:
#<TopicName> <grade1> <grade2> ...
...
```

## Usage

Compile and run the program:
```
gcc main.c calculator.c -o calculator
./calculator
```

### Menu Options

1. **Add a Grade** — Select a class and topic, then enter grades
2. **Add a Class** — Create a new class with credit hours, topics, and weights
3. **Calculate Your GPA** — Calculates weighted average for each class and overall GPA
4. **Delete a Class** — Permanently removes a class file
5. **Exit**

## GPA Calculation

Each topic's grades are averaged and multiplied by its weight. The weighted averages are combined into a final class grade, which is then converted to a 4.0 scale using:

```
GPA = (grade / 100) * 4.0
```

Classes with more credit hours have a greater impact on the overall GPA.

## Platform Support

Works on Windows, macOS, and Linux. Newline differences (`\r\n` vs `\n`) are handled automatically.
