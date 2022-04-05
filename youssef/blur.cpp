void blur() {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

         if(i>=1&&j<SIZE&&i<SIZE&&j>=1){

            image[i][j]= (image[i-1][j-1]+image[i][j-1]+image[i+1][j-1]+image[i-1][j]+image[i][j]+image[i+1][j]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1])/9;

         }
    }
  }
}
