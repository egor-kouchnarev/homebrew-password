# homebrew-password

A CLI random password generator.

### Logic

Returns a 16-character long string using _at least_ one character from each group. Accepts an optional length argument within the range of 4 to 64.

| Group | Characters |
| :--- | :--- |
| Lowercase | a b c d e f g h i j k l m n o p q r s t u v w x y z |
| Uppercase | A B C D E F G H I J K L M N O P Q R S T U V W X Y Z |
| Numbers | 0 1 2 3 4 5 6 7 8 9 |
| Symbols | ! @ # $ % ^ & * |

## Usage

```
password [4-64]
```

### macOS/Linux

Install the [Homebrew](https://brew.sh) package manager.

```
brew tap egor-kouchnarev/tap
brew install password
```
