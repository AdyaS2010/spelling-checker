# Spell-Checker

## Description
This project is a spell-checker written in C that uses a hash table for fast lookups! It loads a dictionary of words into memory, checks if words are in the dictionary, and unloads the dictionary from memory. The program is designed to be especially efficient and fast. 

## Features
- Load a dictionary of words into a hash table
- Check if a word is in the dictionary
- Unload the dictionary from memory
- Use a hash function for fast lookups

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/spell-checker.git
   ```
2. Navigate to the project directory:
   ```bash
   cd speller
   ```
3. Compile the code:
   ```bash
   make speller
   ```

## Usage
1. Run the application:
   ```bash
   ./speller dictionary.txt
   ```
   *Replace `dictionary.txt` with the path to the dictionary file containing the words*.

## Example
```bash
$ ./speller dictionary.txt
Check word: example
Found!
```

## Contributing
1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m 'Add some feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a pull request.

## License
This project is not licensed under any License currently.
