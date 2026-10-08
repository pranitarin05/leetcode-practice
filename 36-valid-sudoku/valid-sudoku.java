import java.util.HashSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {

        // Check every row
        for (int row = 0; row < 9; row++) {

            HashSet<Character> set = new HashSet<>();

            for (int col = 0; col < 9; col++) {

                char value = board[row][col];

                if (value == '.') {
                    continue;
                }

                // Duplicate found in row
                if (set.contains(value)) {
                    return false;
                }

                set.add(value);
            }
        }

        // Check every column
        for (int col = 0; col < 9; col++) {

            HashSet<Character> set = new HashSet<>();

            for (int row = 0; row < 9; row++) {

                char value = board[row][col];

                if (value == '.') {
                    continue;
                }

                // Duplicate found in column
                if (set.contains(value)) {
                    return false;
                }

                set.add(value);
            }
        }

        // Check every 3 x 3 box
        for (int row = 0; row < 9; row += 3) {

            for (int col = 0; col < 9; col += 3) {

                HashSet<Character> set = new HashSet<>();

                // Traverse the current 3 x 3 box
                for (int i = row; i < row + 3; i++) {

                    for (int j = col; j < col + 3; j++) {

                        char value = board[i][j];

                        if (value == '.') {
                            continue;
                        }

                        // Duplicate found in box
                        if (set.contains(value)) {
                            return false;
                        }

                        set.add(value);
                    }
                }
            }
        }

        return true;
    }
}