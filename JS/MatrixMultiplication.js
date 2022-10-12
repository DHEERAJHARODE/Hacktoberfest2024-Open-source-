function outputMultiplication(mat1, mat2) {
  let output = [];
  let row1 = mat1.length;
  let col1 = mat1[0].length;
  let row2 = mat2.length;
  let col2 = mat2[0].length;

  if (col1 != row2) {
    return false;
  }

  for (let i = 0; i < row1; i++) {
    output[i] = [];
    for (let j = 0; j < col2; j++) {
      output[i][j] = 0;
      for (let k = 0; k < col2; k++) {
        output[i][j] = output[i][j] + mat1[i][k] * mat2[k][j];
      }
    }
  }

  return output;
}

function printingMatrix(matrix, row, col) {
  let output = "";
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      output = output + matrix[i][j] + " ";
    }
    output = output.trimEnd();
    output = output + "\n";
  }
  console.log(output);
}

//Test case.
const input = [
  [
    [
      [1, 1],
      [1, 1],
    ],
    [
      [3, 0],
      [0, 5],
    ],
  ],
  [
    [
      [1, 0],
      [0, 1],
    ],
    [
      [1, 2],
      [3, 4],
    ],
  ],
  [
    [
      [1, 1],
      [1, 1],
    ],
    [[3], [0]],
  ],
  [
    [
      [1, 2],
      [3, 4],
    ],
    [
      [1, 2],
      [3, 4],
    ],
  ],
  [
    [
      [1, 0, 0],
      [0, 1, 0],
      [0, 0, 1],
    ],
    [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
    ],
  ],
  [
    [
      [1, 2],
      [3, 4],
    ],
    [
      [1, 2, 3],
      [3, 4, 5],
      [6, 7, 8],
    ],
  ],
];
const output = [
  [
    [3, 5],
    [3, 5],
  ],
  [
    [1, 2],
    [3, 4],
  ],
  [[3], [3]],
  [
    [7, 10],
    [15, 22],
  ],
  [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ],
  false
];
export function tester(input, expOutput, testFn) {
  //expOutput[i] === output[i]
  //expOutput[i] === testFn(input[i])
  if (
    !(
      Array.isArray(input) &&
      Array.isArray(expOutput) &&
      input.length == expOutput.length
    )
  ) {
    if (input.length != expOutput.length) {
      return "array lengths not equal";
    }
    return " Argument not array";
  }
  if (!(typeof testFn === "function")) return "function not defined";

  for (let i = 0; i < input.length; i++) {
    const output = testFn(input[i][0], input[i][1]);
    if (JSON.stringify(output) !== JSON.stringify(expOutput[i])) {
      return `Test failed.
                    Case # : ${i + 1}
                    The expected output: ${expOutput[i]} (${typeof expOutput[
        i
      ]})
                    But got: ${testFn(input[i])} (${typeof testFn(input[i])})`;
    }
  }
  return "test successfull";
}

console.log(tester(input, output, outputMultiplication));
