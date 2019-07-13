using System;
namespace BackPropTraining
{
  class BackPropTrainingProgram
  {
    static void Main(string[] args)
    {
      Console.WriteLine("\nBegin neural network training with back-propagation demo\n");
      Console.WriteLine("\nData is the famous Iris flower set.");
      Console.WriteLine("Data is sepal length, sepal width, petal length, petal width -> iris species");
      Console.WriteLine("Iris setosa = 0 0 1, Iris versicolor = 0 1 0, Iris virginica = 1 0 0 ");
      Console.WriteLine("The goal is to predict species from sepal length, sepal width, petal length, petal width\n");
      
      double[][] allData = new double[150][];
      allData[0] = new double[] { 5.1, 3.5, 1.4, 0.2, 0, 0, 1 }; // sepal length, sepal width, petal length, petal width -> 
      allData[1] = new double[] { 4.9, 3.0, 1.4, 0.2, 0, 0, 1 }; // Iris setosa = 0 0 1, Iris versicolor = 0 1 0, Iris virginica = 1 0 0
      allData[2] = new double[] { 4.7, 3.2, 1.3, 0.2, 0, 0, 1 };
      allData[3] = new double[] { 4.6, 3.1, 1.5, 0.2, 0, 0, 1 };
      allData[4] = new double[] { 5.0, 3.6, 1.4, 0.2, 0, 0, 1 };
      allData[5] = new double[] { 5.4, 3.9, 1.7, 0.4, 0, 0, 1 };
      allData[6] = new double[] { 4.6, 3.4, 1.4, 0.3, 0, 0, 1 };
      allData[7] = new double[] { 5.0, 3.4, 1.5, 0.2, 0, 0, 1 };
      allData[8] = new double[] { 4.4, 2.9, 1.4, 0.2, 0, 0, 1 };
      allData[9] = new double[] { 4.9, 3.1, 1.5, 0.1, 0, 0, 1 };

      allData[10] = new double[] { 5.4, 3.7, 1.5, 0.2, 0, 0, 1 };
      allData[11] = new double[] { 4.8, 3.4, 1.6, 0.2, 0, 0, 1 };
      allData[12] = new double[] { 4.8, 3.0, 1.4, 0.1, 0, 0, 1 };
      allData[13] = new double[] { 4.3, 3.0, 1.1, 0.1, 0, 0, 1 };
      allData[14] = new double[] { 5.8, 4.0, 1.2, 0.2, 0, 0, 1 };
      allData[15] = new double[] { 5.7, 4.4, 1.5, 0.4, 0, 0, 1 };
      allData[16] = new double[] { 5.4, 3.9, 1.3, 0.4, 0, 0, 1 };
      allData[17] = new double[] { 5.1, 3.5, 1.4, 0.3, 0, 0, 1 };
      allData[18] = new double[] { 5.7, 3.8, 1.7, 0.3, 0, 0, 1 };
      allData[19] = new double[] { 5.1, 3.8, 1.5, 0.3, 0, 0, 1 };

      allData[20] = new double[] { 5.4, 3.4, 1.7, 0.2, 0, 0, 1 };
      allData[21] = new double[] { 5.1, 3.7, 1.5, 0.4, 0, 0, 1 };
      allData[22] = new double[] { 4.6, 3.6, 1.0, 0.2, 0, 0, 1 };
      allData[23] = new double[] { 5.1, 3.3, 1.7, 0.5, 0, 0, 1 };
      allData[24] = new double[] { 4.8, 3.4, 1.9, 0.2, 0, 0, 1 };
      allData[25] = new double[] { 5.0, 3.0, 1.6, 0.2, 0, 0, 1 };
      allData[26] = new double[] { 5.0, 3.4, 1.6, 0.4, 0, 0, 1 };
      allData[27] = new double[] { 5.2, 3.5, 1.5, 0.2, 0, 0, 1 };
      allData[28] = new double[] { 5.2, 3.4, 1.4, 0.2, 0, 0, 1 };
      allData[29] = new double[] { 4.7, 3.2, 1.6, 0.2, 0, 0, 1 };

      allData[30] = new double[] { 4.8, 3.1, 1.6, 0.2, 0, 0, 1 };
      allData[31] = new double[] { 5.4, 3.4, 1.5, 0.4, 0, 0, 1 };
      allData[32] = new double[] { 5.2, 4.1, 1.5, 0.1, 0, 0, 1 };
      allData[33] = new double[] { 5.5, 4.2, 1.4, 0.2, 0, 0, 1 };
      allData[34] = new double[] { 4.9, 3.1, 1.5, 0.1, 0, 0, 1 };
      allData[35] = new double[] { 5.0, 3.2, 1.2, 0.2, 0, 0, 1 };
      allData[36] = new double[] { 5.5, 3.5, 1.3, 0.2, 0, 0, 1 };
      allData[37] = new double[] { 4.9, 3.1, 1.5, 0.1, 0, 0, 1 };
      allData[38] = new double[] { 4.4, 3.0, 1.3, 0.2, 0, 0, 1 };
      allData[39] = new double[] { 5.1, 3.4, 1.5, 0.2, 0, 0, 1 };

      allData[40] = new double[] { 5.0, 3.5, 1.3, 0.3, 0, 0, 1 };
      allData[41] = new double[] { 4.5, 2.3, 1.3, 0.3, 0, 0, 1 };
      allData[42] = new double[] { 4.4, 3.2, 1.3, 0.2, 0, 0, 1 };
      allData[43] = new double[] { 5.0, 3.5, 1.6, 0.6, 0, 0, 1 };
      allData[44] = new double[] { 5.1, 3.8, 1.9, 0.4, 0, 0, 1 };
      allData[45] = new double[] { 4.8, 3.0, 1.4, 0.3, 0, 0, 1 };
      allData[46] = new double[] { 5.1, 3.8, 1.6, 0.2, 0, 0, 1 };
      allData[47] = new double[] { 4.6, 3.2, 1.4, 0.2, 0, 0, 1 };
      allData[48] = new double[] { 5.3, 3.7, 1.5, 0.2, 0, 0, 1 };
      allData[49] = new double[] { 5.0, 3.3, 1.4, 0.2, 0, 0, 1 };

      allData[50] = new double[] { 7.0, 3.2, 4.7, 1.4, 0, 1, 0 };
      allData[51] = new double[] { 6.4, 3.2, 4.5, 1.5, 0, 1, 0 };
      allData[52] = new double[] { 6.9, 3.1, 4.9, 1.5, 0, 1, 0 };
      allData[53] = new double[] { 5.5, 2.3, 4.0, 1.3, 0, 1, 0 };
      allData[54] = new double[] { 6.5, 2.8, 4.6, 1.5, 0, 1, 0 };
      allData[55] = new double[] { 5.7, 2.8, 4.5, 1.3, 0, 1, 0 };
      allData[56] = new double[] { 6.3, 3.3, 4.7, 1.6, 0, 1, 0 };
      allData[57] = new double[] { 4.9, 2.4, 3.3, 1.0, 0, 1, 0 };
      allData[58] = new double[] { 6.6, 2.9, 4.6, 1.3, 0, 1, 0 };
      allData[59] = new double[] { 5.2, 2.7, 3.9, 1.4, 0, 1, 0 };

      allData[60] = new double[] { 5.0, 2.0, 3.5, 1.0, 0, 1, 0 };
      allData[61] = new double[] { 5.9, 3.0, 4.2, 1.5, 0, 1, 0 };
      allData[62] = new double[] { 6.0, 2.2, 4.0, 1.0, 0, 1, 0 };
      allData[63] = new double[] { 6.1, 2.9, 4.7, 1.4, 0, 1, 0 };
      allData[64] = new double[] { 5.6, 2.9, 3.6, 1.3, 0, 1, 0 };
      allData[65] = new double[] { 6.7, 3.1, 4.4, 1.4, 0, 1, 0 };
      allData[66] = new double[] { 5.6, 3.0, 4.5, 1.5, 0, 1, 0 };
      allData[67] = new double[] { 5.8, 2.7, 4.1, 1.0, 0, 1, 0 };
      allData[68] = new double[] { 6.2, 2.2, 4.5, 1.5, 0, 1, 0 };
      allData[69] = new double[] { 5.6, 2.5, 3.9, 1.1, 0, 1, 0 };

      allData[70] = new double[] { 5.9, 3.2, 4.8, 1.8, 0, 1, 0 };
      allData[71] = new double[] { 6.1, 2.8, 4.0, 1.3, 0, 1, 0 };
      allData[72] = new double[] { 6.3, 2.5, 4.9, 1.5, 0, 1, 0 };
      allData[73] = new double[] { 6.1, 2.8, 4.7, 1.2, 0, 1, 0 };
      allData[74] = new double[] { 6.4, 2.9, 4.3, 1.3, 0, 1, 0 };
      allData[75] = new double[] { 6.6, 3.0, 4.4, 1.4, 0, 1, 0 };
      allData[76] = new double[] { 6.8, 2.8, 4.8, 1.4, 0, 1, 0 };
      allData[77] = new double[] { 6.7, 3.0, 5.0, 1.7, 0, 1, 0 };
      allData[78] = new double[] { 6.0, 2.9, 4.5, 1.5, 0, 1, 0 };
      allData[79] = new double[] { 5.7, 2.6, 3.5, 1.0, 0, 1, 0 };

      allData[80] = new double[] { 5.5, 2.4, 3.8, 1.1, 0, 1, 0 };
      allData[81] = new double[] { 5.5, 2.4, 3.7, 1.0, 0, 1, 0 };
      allData[82] = new double[] { 5.8, 2.7, 3.9, 1.2, 0, 1, 0 };
      allData[83] = new double[] { 6.0, 2.7, 5.1, 1.6, 0, 1, 0 };
      allData[84] = new double[] { 5.4, 3.0, 4.5, 1.5, 0, 1, 0 };
      allData[85] = new double[] { 6.0, 3.4, 4.5, 1.6, 0, 1, 0 };
      allData[86] = new double[] { 6.7, 3.1, 4.7, 1.5, 0, 1, 0 };
      allData[87] = new double[] { 6.3, 2.3, 4.4, 1.3, 0, 1, 0 };
      allData[88] = new double[] { 5.6, 3.0, 4.1, 1.3, 0, 1, 0 };
      allData[89] = new double[] { 5.5, 2.5, 4.0, 1.3, 0, 1, 0 };

      allData[90] = new double[] { 5.5, 2.6, 4.4, 1.2, 0, 1, 0 };
      allData[91] = new double[] { 6.1, 3.0, 4.6, 1.4, 0, 1, 0 };
      allData[92] = new double[] { 5.8, 2.6, 4.0, 1.2, 0, 1, 0 };
      allData[93] = new double[] { 5.0, 2.3, 3.3, 1.0, 0, 1, 0 };
      allData[94] = new double[] { 5.6, 2.7, 4.2, 1.3, 0, 1, 0 };
      allData[95] = new double[] { 5.7, 3.0, 4.2, 1.2, 0, 1, 0 };
      allData[96] = new double[] { 5.7, 2.9, 4.2, 1.3, 0, 1, 0 };
      allData[97] = new double[] { 6.2, 2.9, 4.3, 1.3, 0, 1, 0 };
      allData[98] = new double[] { 5.1, 2.5, 3.0, 1.1, 0, 1, 0 };
      allData[99] = new double[] { 5.7, 2.8, 4.1, 1.3, 0, 1, 0 };

      allData[100] = new double[] { 6.3, 3.3, 6.0, 2.5, 1, 0, 0 };
      allData[101] = new double[] { 5.8, 2.7, 5.1, 1.9, 1, 0, 0 };
      allData[102] = new double[] { 7.1, 3.0, 5.9, 2.1, 1, 0, 0 };
      allData[103] = new double[] { 6.3, 2.9, 5.6, 1.8, 1, 0, 0 };
      allData[104] = new double[] { 6.5, 3.0, 5.8, 2.2, 1, 0, 0 };
      allData[105] = new double[] { 7.6, 3.0, 6.6, 2.1, 1, 0, 0 };
      allData[106] = new double[] { 4.9, 2.5, 4.5, 1.7, 1, 0, 0 };
      allData[107] = new double[] { 7.3, 2.9, 6.3, 1.8, 1, 0, 0 };
      allData[108] = new double[] { 6.7, 2.5, 5.8, 1.8, 1, 0, 0 };
      allData[109] = new double[] { 7.2, 3.6, 6.1, 2.5, 1, 0, 0 };

      allData[110] = new double[] { 6.5, 3.2, 5.1, 2.0, 1, 0, 0 };
      allData[111] = new double[] { 6.4, 2.7, 5.3, 1.9, 1, 0, 0 };
      allData[112] = new double[] { 6.8, 3.0, 5.5, 2.1, 1, 0, 0 };
      allData[113] = new double[] { 5.7, 2.5, 5.0, 2.0, 1, 0, 0 };
      allData[114] = new double[] { 5.8, 2.8, 5.1, 2.4, 1, 0, 0 };
      allData[115] = new double[] { 6.4, 3.2, 5.3, 2.3, 1, 0, 0 };
      allData[116] = new double[] { 6.5, 3.0, 5.5, 1.8, 1, 0, 0 };
      allData[117] = new double[] { 7.7, 3.8, 6.7, 2.2, 1, 0, 0 };
      allData[118] = new double[] { 7.7, 2.6, 6.9, 2.3, 1, 0, 0 };
      allData[119] = new double[] { 6.0, 2.2, 5.0, 1.5, 1, 0, 0 };

      allData[120] = new double[] { 6.9, 3.2, 5.7, 2.3, 1, 0, 0 };
      allData[121] = new double[] { 5.6, 2.8, 4.9, 2.0, 1, 0, 0 };
      allData[122] = new double[] { 7.7, 2.8, 6.7, 2.0, 1, 0, 0 };
      allData[123] = new double[] { 6.3, 2.7, 4.9, 1.8, 1, 0, 0 };
      allData[124] = new double[] { 6.7, 3.3, 5.7, 2.1, 1, 0, 0 };
      allData[125] = new double[] { 7.2, 3.2, 6.0, 1.8, 1, 0, 0 };
      allData[126] = new double[] { 6.2, 2.8, 4.8, 1.8, 1, 0, 0 };
      allData[127] = new double[] { 6.1, 3.0, 4.9, 1.8, 1, 0, 0 };
      allData[128] = new double[] { 6.4, 2.8, 5.6, 2.1, 1, 0, 0 };
      allData[129] = new double[] { 7.2, 3.0, 5.8, 1.6, 1, 0, 0 };

      allData[130] = new double[] { 7.4, 2.8, 6.1, 1.9, 1, 0, 0 };
      allData[131] = new double[] { 7.9, 3.8, 6.4, 2.0, 1, 0, 0 };
      allData[132] = new double[] { 6.4, 2.8, 5.6, 2.2, 1, 0, 0 };
      allData[133] = new double[] { 6.3, 2.8, 5.1, 1.5, 1, 0, 0 };
      allData[134] = new double[] { 6.1, 2.6, 5.6, 1.4, 1, 0, 0 };
      allData[135] = new double[] { 7.7, 3.0, 6.1, 2.3, 1, 0, 0 };
      allData[136] = new double[] { 6.3, 3.4, 5.6, 2.4, 1, 0, 0 };
      allData[137] = new double[] { 6.4, 3.1, 5.5, 1.8, 1, 0, 0 };
      allData[138] = new double[] { 6.0, 3.0, 4.8, 1.8, 1, 0, 0 };
      allData[139] = new double[] { 6.9, 3.1, 5.4, 2.1, 1, 0, 0 };

      allData[140] = new double[] { 6.7, 3.1, 5.6, 2.4, 1, 0, 0 };
      allData[141] = new double[] { 6.9, 3.1, 5.1, 2.3, 1, 0, 0 };
      allData[142] = new double[] { 5.8, 2.7, 5.1, 1.9, 1, 0, 0 };
      allData[143] = new double[] { 6.8, 3.2, 5.9, 2.3, 1, 0, 0 };
      allData[144] = new double[] { 6.7, 3.3, 5.7, 2.5, 1, 0, 0 };
      allData[145] = new double[] { 6.7, 3.0, 5.2, 2.3, 1, 0, 0 };
      allData[146] = new double[] { 6.3, 2.5, 5.0, 1.9, 1, 0, 0 };
      allData[147] = new double[] { 6.5, 3.0, 5.2, 2.0, 1, 0, 0 };
      allData[148] = new double[] { 6.2, 3.4, 5.4, 2.3, 1, 0, 0 };
      allData[149] = new double[] { 5.9, 3.0, 5.1, 1.8, 1, 0, 0 };

      Console.WriteLine("First 10 rows of entire 150-item data set:");
      ShowMatrix(allData, 10, 1, true);

      Console.WriteLine("\nCreating 80% training and 20% test data matrices");
      double[][] trainData = null;
      double[][] testData = null;
      MakeTrainTest(allData, out trainData, out testData);

      Console.WriteLine("\nFirst 8 rows of training data:");
      ShowMatrix(trainData, 8, 1, true);
      Console.WriteLine("First 6 rows of test data:");
      ShowMatrix(testData, 6, 1, true);

      //Normalize(trainData, new int[] { 0, 1, 2, 3 });
      //Normalize(testData, new int[] { 0, 1, 2, 3 });

      //Console.WriteLine("\nFirst 8 rows of normalized training data:");
      //ShowMatrix(trainData, 8, 1, true);
      //Console.WriteLine("First 6 rows of normalized test data:");
      //ShowMatrix(testData, 6, 1, true);

      Console.WriteLine("\nCreating a 4-input, 7-hidden, 3-output neural network");
      Console.WriteLine("Hard-coded tanh function for input-to-hidden and softmax for hidden-to-output activations");
      const int numInput = 4;
      const int numHidden = 7;
      const int numOutput = 3;
      NeuralNetwork nn = new NeuralNetwork(numInput, numHidden, numOutput);

      Console.WriteLine("\nInitializing weights and bias to small random values");
      nn.InitializeWeights();
      
      int maxEpochs = 500;
      double learnRate = 0.05;
      double momentum = 0.01;
      Console.WriteLine("Setting maxEpochs = 2000, learnRate = 0.05, momentum = 0.01");
      Console.WriteLine("Training has hard-coded mean squared error < 0.001 stopping condition");

      Console.WriteLine("\nBeginning training using incremental back-propagation\n");
      nn.Train(trainData, maxEpochs, learnRate, momentum); // back-propagation
      Console.WriteLine("\nTraining complete");

      double[] weights = nn.GetWeights();
      Console.WriteLine("Final neural network weights and bias values:");
      ShowVector(weights, 10, 3, true);

      double trainAcc = nn.Accuracy(trainData);
      Console.WriteLine("\nAccuracy on training data = " + trainAcc.ToString("F4"));

      double testAcc = nn.Accuracy(testData);
      Console.WriteLine("\nAccuracy on test data = " + testAcc.ToString("F4"));

      Console.WriteLine("\nEnd neural network training with back-propagation demo\n");
      Console.ReadLine();

    } // Main

    static void MakeTrainTest(double[][] allData, out double[][] trainData, out double[][] testData)
    {
      // split allData into 80% trainData and 20% testData
      Random rnd = new Random(0);
      int totRows = allData.Length;
      int numCols = allData[0].Length;

      int trainRows = (int)(totRows * 0.80); // hard-coded 80-20 split
      int testRows = totRows - trainRows;

      trainData = new double[trainRows][];
      testData = new double[testRows][];

      int[] sequence = new int[totRows]; // create a random sequence of indexes
      for (int i = 0; i < sequence.Length; ++i)
        sequence[i] = i;

      for (int i = 0; i < sequence.Length; ++i)
      {
        int r = rnd.Next(i, sequence.Length);
        int tmp = sequence[r];
        sequence[r] = sequence[i];
        sequence[i] = tmp;
      }

      int si = 0; // index into sequence[]
      int j = 0; // index into trainData or testData

      for (; si < trainRows; ++si) // first rows to train data
      {
        trainData[j] = new double[numCols];
        int idx = sequence[si];
        Array.Copy(allData[idx], trainData[j], numCols);
        ++j;
      }

      j = 0; // reset to start of test data
      for (; si < totRows; ++si) // remainder to test data
      {
        testData[j] = new double[numCols];
        int idx = sequence[si];
        Array.Copy(allData[idx], testData[j], numCols);
        ++j;
      }
    } // MakeTrainTest

    //static void Normalize(double[][] dataMatrix, int[] cols)
    //{
    //  // normalize specified cols by computing (x - mean) / sd for each value
    //  foreach (int col in cols)
    //  {
    //    double sum = 0.0;
    //    for (int i = 0; i < dataMatrix.Length; ++i)
    //      sum += dataMatrix[i][col];
    //    double mean = sum / dataMatrix.Length;
    //    sum = 0.0;
    //    for (int i = 0; i < dataMatrix.Length; ++i)
    //      sum += (dataMatrix[i][col] - mean) * (dataMatrix[i][col] - mean);
    //    double sd = sum / (dataMatrix.Length - 1);
    //    for (int i = 0; i < dataMatrix.Length; ++i)
    //      dataMatrix[i][col] = (dataMatrix[i][col] - mean) / sd;
    //  }
    //}

    static void ShowVector(double[] vector, int valsPerRow, int decimals, bool newLine)
    {
      for (int i = 0; i < vector.Length; ++i)
      {
        if (i % valsPerRow == 0) Console.WriteLine("");
        Console.Write(vector[i].ToString("F" + decimals).PadLeft(decimals + 4) + " ");
      }
      if (newLine == true) Console.WriteLine("");
    }

    static void ShowMatrix(double[][] matrix, int numRows, int decimals, bool newLine)
    {
      for (int i = 0; i < numRows; ++i)
      {
        Console.Write(i.ToString().PadLeft(3) + ": ");
        for (int j = 0; j < matrix[i].Length; ++j)
        {
          Console.Write(matrix[i][j].ToString("F"+decimals) + " ");
        }
        Console.WriteLine("");
      }
      if (newLine == true) Console.WriteLine("");
    }

  } // class Program

  public class NeuralNetwork
  {
    private static Random rnd;

    private int numInput;
    private int numHidden;
    private int numOutput;

    private double[] inputs;

    private double[][] ihWeights; // input-hidden
    private double[] hBiases;
    private double[] hOutputs;

    private double[][] hoWeights; // hidden-output
    private double[] oBiases;

    private double[] outputs;

    // back-prop specific arrays (these could be local to UpdateWeights)
    private double[] oGrads; // output gradients for back-propagation
    private double[] hGrads; // hidden gradients for back-propagation

    // back-prop momentum specific arrays (necessary as class members)
    private double[][] ihPrevWeightsDelta;  // for momentum with back-propagation
    private double[] hPrevBiasesDelta;
    private double[][] hoPrevWeightsDelta;
    private double[] oPrevBiasesDelta;


    public NeuralNetwork(int numInput, int numHidden, int numOutput)
    {
      rnd = new Random(0); // for InitializeWeights() and Shuffle()

      this.numInput = numInput;
      this.numHidden = numHidden;
      this.numOutput = numOutput;

      this.inputs = new double[numInput];

      this.ihWeights = MakeMatrix(numInput, numHidden);
      this.hBiases = new double[numHidden];
      this.hOutputs = new double[numHidden];

      this.hoWeights = MakeMatrix(numHidden, numOutput);
      this.oBiases = new double[numOutput];

      this.outputs = new double[numOutput];

      // back-prop related arrays below
      this.hGrads = new double[numHidden];
      this.oGrads = new double[numOutput];
      
      this.ihPrevWeightsDelta = MakeMatrix(numInput, numHidden);
      this.hPrevBiasesDelta = new double[numHidden];
      this.hoPrevWeightsDelta = MakeMatrix(numHidden, numOutput);
      this.oPrevBiasesDelta = new double[numOutput];
    } // ctor

    private static double[][] MakeMatrix(int rows, int cols) // helper for ctor
    {
      double[][] result = new double[rows][];
      for (int r = 0; r < result.Length; ++r)
        result[r] = new double[cols];
      return result;
    }

    public override string ToString() // yikes
    {
      string s = "";
      s += "===============================\n";
      s += "numInput = " + numInput + " numHidden = " + numHidden + " numOutput = " + numOutput + "\n\n";

      s += "inputs: \n";
      for (int i = 0; i < inputs.Length; ++i)
        s += inputs[i].ToString("F2") + " ";
      s += "\n\n";

      s += "ihWeights: \n";
      for (int i = 0; i < ihWeights.Length; ++i)
      {
        for (int j = 0; j < ihWeights[i].Length; ++j)
        {
          s += ihWeights[i][j].ToString("F4") + " ";
        }
        s += "\n";
      }
      s += "\n";

      s += "hBiases: \n";
      for (int i = 0; i < hBiases.Length; ++i)
        s += hBiases[i].ToString("F4") + " ";
      s += "\n\n";

      s += "hOutputs: \n";
      for (int i = 0; i < hOutputs.Length; ++i)
        s += hOutputs[i].ToString("F4") + " ";
      s += "\n\n";

      s += "hoWeights: \n";
      for (int i = 0; i < hoWeights.Length; ++i)
      {
        for (int j = 0; j < hoWeights[i].Length; ++j)
        {
          s += hoWeights[i][j].ToString("F4") + " ";
        }
        s += "\n";
      }
      s += "\n";

      s += "oBiases: \n";
      for (int i = 0; i < oBiases.Length; ++i)
        s += oBiases[i].ToString("F4") + " ";
      s += "\n\n";

      s += "hGrads: \n";
      for (int i = 0; i < hGrads.Length; ++i)
        s += hGrads[i].ToString("F4") + " ";
      s += "\n\n";

      s += "oGrads: \n";
      for (int i = 0; i < oGrads.Length; ++i)
        s += oGrads[i].ToString("F4") + " ";
      s += "\n\n";

      s += "ihPrevWeightsDelta: \n";
      for (int i = 0; i < ihPrevWeightsDelta.Length; ++i)
      {
        for (int j = 0; j < ihPrevWeightsDelta[i].Length; ++j)
        {
          s += ihPrevWeightsDelta[i][j].ToString("F4") + " ";
        }
        s += "\n";
      }
      s += "\n";

      s += "hPrevBiasesDelta: \n";
      for (int i = 0; i < hPrevBiasesDelta.Length; ++i)
        s += hPrevBiasesDelta[i].ToString("F4") + " ";
      s += "\n\n";

      s += "hoPrevWeightsDelta: \n";
      for (int i = 0; i < hoPrevWeightsDelta.Length; ++i)
      {
        for (int j = 0; j < hoPrevWeightsDelta[i].Length; ++j)
        {
          s += hoPrevWeightsDelta[i][j].ToString("F4") + " ";
        }
        s += "\n";
      }
      s += "\n";

      s += "oPrevBiasesDelta: \n";
      for (int i = 0; i < oPrevBiasesDelta.Length; ++i)
        s += oPrevBiasesDelta[i].ToString("F4") + " ";
      s += "\n\n";

      s += "outputs: \n";
      for (int i = 0; i < outputs.Length; ++i)
        s += outputs[i].ToString("F2") + " ";
      s += "\n\n";

      s += "===============================\n";
      return s;
    }

    // ----------------------------------------------------------------------------------------

    public void SetWeights(double[] weights)
    {
      // copy weights and biases in weights[] array to i-h weights, i-h biases, h-o weights, h-o biases
      int numWeights = (numInput * numHidden) + (numHidden * numOutput) + numHidden + numOutput;
      if (weights.Length != numWeights)
        throw new Exception("Bad weights array length: ");

      int k = 0; // points into weights param

      for (int i = 0; i < numInput; ++i)
        for (int j = 0; j < numHidden; ++j)
          ihWeights[i][j] = weights[k++];
      for (int i = 0; i < numHidden; ++i)
        hBiases[i] = weights[k++];
      for (int i = 0; i < numHidden; ++i)
        for (int j = 0; j < numOutput; ++j)
          hoWeights[i][j] = weights[k++];
      for (int i = 0; i < numOutput; ++i)
        oBiases[i] = weights[k++];
    }

    public void InitializeWeights()
    {
      // initialize weights and biases to small random values
      int numWeights = (numInput * numHidden) + (numHidden * numOutput) + numHidden + numOutput;
      double[] initialWeights = new double[numWeights];
      for (int i = 0; i < initialWeights.Length; ++i)
        initialWeights[i] = (0.001 - 0.0001) * rnd.NextDouble() + 0.0001;
      this.SetWeights(initialWeights);
    }

    public double[] GetWeights()
    {
      // returns the current set of wweights, presumably after training
      int numWeights = (numInput * numHidden) + (numHidden * numOutput) + numHidden + numOutput;
      double[] result = new double[numWeights];
      int k = 0;
      for (int i = 0; i < ihWeights.Length; ++i)
        for (int j = 0; j < ihWeights[0].Length; ++j)
          result[k++] = ihWeights[i][j];
      for (int i = 0; i < hBiases.Length; ++i)
        result[k++] = hBiases[i];
      for (int i = 0; i < hoWeights.Length; ++i)
        for (int j = 0; j < hoWeights[0].Length; ++j)
          result[k++] = hoWeights[i][j];
      for (int i = 0; i < oBiases.Length; ++i)
        result[k++] = oBiases[i];
      return result;
    }

    // ----------------------------------------------------------------------------------------

    private double[] ComputeOutputs(double[] xValues)
    {
      if (xValues.Length != numInput)
        throw new Exception("Bad xValues array length");

      double[] hSums = new double[numHidden]; // hidden nodes sums scratch array
      double[] oSums = new double[numOutput]; // output nodes sums

      for (int i = 0; i < xValues.Length; ++i) // copy x-values to inputs
        this.inputs[i] = xValues[i];

      for (int j = 0; j < numHidden; ++j)  // compute i-h sum of weights * inputs
        for (int i = 0; i < numInput; ++i)
          hSums[j] += this.inputs[i] * this.ihWeights[i][j]; // note +=

      for (int i = 0; i < numHidden; ++i)  // add biases to input-to-hidden sums
        hSums[i] += this.hBiases[i];

      for (int i = 0; i < numHidden; ++i)   // apply activation
        this.hOutputs[i] = HyperTanFunction(hSums[i]); // hard-coded

      for (int j = 0; j < numOutput; ++j)   // compute h-o sum of weights * hOutputs
        for (int i = 0; i < numHidden; ++i)
          oSums[j] += hOutputs[i] * hoWeights[i][j];

      for (int i = 0; i < numOutput; ++i)  // add biases to input-to-hidden sums
        oSums[i] += oBiases[i];

      double[] softOut = Softmax(oSums); // softmax activation does all outputs at once for efficiency
      Array.Copy(softOut, outputs, softOut.Length);

      double[] retResult = new double[numOutput]; // could define a GetOutputs method instead
      Array.Copy(this.outputs, retResult, retResult.Length);
      return retResult;
    } // ComputeOutputs

    private static double HyperTanFunction(double x)
    {
      if (x < -20.0) return -1.0; // approximation is correct to 30 decimals
      else if (x > 20.0) return 1.0;
      else return Math.Tanh(x);
    }

    private static double[] Softmax(double[] oSums) // does all output nodes at once so scale doesn't have to be re-computed each time
    {
      // determine max output sum
      double max = oSums[0];
      for (int i = 0; i < oSums.Length; ++i)
        if (oSums[i] > max) max = oSums[i];

      // determine scaling factor -- sum of exp(each val - max)
      double scale = 0.0;
      for (int i = 0; i < oSums.Length; ++i)
        scale += Math.Exp(oSums[i] - max);

      double[] result = new double[oSums.Length];
      for (int i = 0; i < oSums.Length; ++i)
        result[i] = Math.Exp(oSums[i] - max) / scale;

      return result; // now scaled so that xi sum to 1.0
    }

    // ----------------------------------------------------------------------------------------

    private void UpdateWeights(double[] tValues, double learnRate, double momentum)
    {
      // update the weights and biases using back-propagation, with target values, eta (learning rate), alpha (momentum)
      // assumes that SetWeights and ComputeOutputs have been called and so all the internal arrays and matrices have values (other than 0.0)
      if (tValues.Length != numOutput)
        throw new Exception("target values not same Length as output in UpdateWeights");

      // 1. compute output gradients
      for (int i = 0; i < oGrads.Length; ++i)
      {
        double derivative = (1 - outputs[i]) * outputs[i]; // derivative of softmax = (1 - y) * y (same as log-sigmoid)
        oGrads[i] = derivative * (tValues[i] - outputs[i]); // 'mean squared error version' includes (1-y)(y) derivative
        //oGrads[i] = (tValues[i] - outputs[i]); // cross-entropy version drops (1-y)(y) term! See http://www.cs.mcgill.ca/~dprecup/courses/ML/Lectures/ml-lecture05.pdf page 25.
      }

      // 2. compute hidden gradients
      for (int i = 0; i < hGrads.Length; ++i)
      {
        double derivative = (1 - hOutputs[i]) * (1 + hOutputs[i]); // derivative of tanh = (1 - y) * (1 + y)
        double sum = 0.0;
        for (int j = 0; j < numOutput; ++j) // each hidden delta is the sum of numOutput terms
        {
          double x = oGrads[j] * hoWeights[i][j];
          sum += x;
        }
        hGrads[i] = derivative * sum;
      }

      // 3a. update hidden weights (gradients must be computed right-to-left but weights can be updated in any order)
      for (int i = 0; i < ihWeights.Length; ++i) // 0..2 (3)
      {
        for (int j = 0; j < ihWeights[0].Length; ++j) // 0..3 (4)
        {
          double delta = learnRate * hGrads[j] * inputs[i]; // compute the new delta
          ihWeights[i][j] += delta; // update. note we use '+' instead of '-'. this can be very tricky.
          ihWeights[i][j] += momentum * ihPrevWeightsDelta[i][j]; // add momentum using previous delta. on first pass old value will be 0.0 but that's OK.
          ihPrevWeightsDelta[i][j] = delta; // don't forget to save the delta for momentum 
        }
      }

      // 3b. update hidden biases
      for (int i = 0; i < hBiases.Length; ++i)
      {
        double delta = learnRate * hGrads[i] * 1.0; // the 1.0 is the constant input for any bias; could leave out
        hBiases[i] += delta;
        hBiases[i] += momentum * hPrevBiasesDelta[i]; // momentum
        hPrevBiasesDelta[i] = delta; // don't forget to save the delta
      }

      // 4. update hidden-output weights
      for (int i = 0; i < hoWeights.Length; ++i)
      {
        for (int j = 0; j < hoWeights[0].Length; ++j)
        {
          double delta = learnRate * oGrads[j] * hOutputs[i];  // see above: hOutputs are inputs to the nn outputs
          hoWeights[i][j] += delta;
          hoWeights[i][j] += momentum * hoPrevWeightsDelta[i][j]; // momentum
          hoPrevWeightsDelta[i][j] = delta; // save
        }
      }

      // 4b. update output biases
      for (int i = 0; i < oBiases.Length; ++i)
      {
        double delta = learnRate * oGrads[i] * 1.0;
        oBiases[i] += delta;
        oBiases[i] += momentum * oPrevBiasesDelta[i]; // momentum
        oPrevBiasesDelta[i] = delta; // save
      }
    } // UpdateWeights

    // ----------------------------------------------------------------------------------------

    public void Train(double[][] trainData, int maxEprochs, double learnRate, double momentum)
    {
      // train a back-prop style NN classifier using learning rate and momentum
      int epoch = 0;
      double[] xValues = new double[numInput]; // inputs
      double[] tValues = new double[numOutput]; // target values

      int[] sequence = new int[trainData.Length];
      for (int i = 0; i < sequence.Length; ++i)
        sequence[i] = i;

      while (epoch < maxEprochs)
      {
        double mse = MeanSquaredError(trainData);
        if (mse < 0.001) break; // consider passing value in as parameter

        Shuffle(sequence); // visit each training data in random order
        for (int i = 0; i < trainData.Length; ++i)
        {
          int idx = sequence[i];
          Array.Copy(trainData[idx], xValues, numInput); // more flexible might be a 'GetInputsAndTargets()'
          Array.Copy(trainData[idx], numInput, tValues, 0, numOutput);
          ComputeOutputs(xValues); // copy xValues in, compute outputs (and store them internally)
          UpdateWeights(tValues, learnRate, momentum); // use curr outputs and targets and back-prop to find better weights
        } // each training tuple
        ++epoch;
      }
    } // Train

    private static void Shuffle(int[] sequence)
    {
      for (int i = 0; i < sequence.Length; ++i)
      {
        int r = rnd.Next(i, sequence.Length);
        int tmp = sequence[r];
        sequence[r] = sequence[i];
        sequence[i] = tmp;
      }
    }

    private double MeanSquaredError(double[][] trainData) // used as a training stopping condition
    {
      // average squared error per training tuple
      double sumSquaredError = 0.0;
      double[] xValues = new double[numInput]; // first numInput values in trainData
      double[] tValues = new double[numOutput]; // last numOutput values

      for (int i = 0; i < trainData.Length; ++i) // walk thru each training case. looks like (6.9 3.2 5.7 2.3) (0 0 1)  where the parens are not really there
      {
        Array.Copy(trainData[i], xValues, numInput); // get xValues. more flexible would be a 'GetInputsAndTargets()'
        Array.Copy(trainData[i], numInput, tValues, 0, numOutput); // get target values
        double[] yValues = this.ComputeOutputs(xValues); // compute output using current weights
        for (int j = 0; j < numOutput; ++j)
        {
          double err = tValues[j] - yValues[j];
          sumSquaredError += err * err;
        }
      }

      return sumSquaredError / trainData.Length;
    }

    // ----------------------------------------------------------------------------------------

    public double Accuracy(double[][] testData)
    {
      // percentage correct using winner-takes all
      int numCorrect = 0;
      int numWrong = 0;
      double[] xValues = new double[numInput]; // inputs
      double[] tValues = new double[numOutput]; // targets
      double[] yValues; // computed Y

      for (int i = 0; i < testData.Length; ++i)
      {
        Array.Copy(testData[i], xValues, numInput); // parse test data into x-values and t-values
        Array.Copy(testData[i], numInput, tValues, 0, numOutput);
        yValues = this.ComputeOutputs(xValues);
        int maxIndex = MaxIndex(yValues); // which cell in yValues has largest value?

        if (tValues[maxIndex] == 1.0) // ugly. consider AreEqual(double x, double y)
          ++numCorrect; 
        else
          ++numWrong; 
      }
      return (numCorrect * 1.0) / (numCorrect + numWrong); // ugly 2 - check for divide by zero
    }

    private static int MaxIndex(double[] vector) // helper for Accuracy()
    {
      // index of largest value
      int bigIndex = 0;
      double biggestVal = vector[0];
      for (int i = 0; i < vector.Length; ++i)
      {
        if (vector[i] > biggestVal)
        {
          biggestVal = vector[i]; bigIndex = i;
        }
      }
      return bigIndex;
    }

    

  } // NeuralNetwork

} // ns
