void detect_edge() {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

           if(image[i][j]==image[i][j+1]&&image[i][j]==image[i+1][j]&&image[i][j]==image[i+1][j+1]){
                    image[i][j]=255;
           }
           else{
                image[i][j]=0;
           }
    }
  }
}

void black_white() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

            if (image[i][j] > 127)
            image[i][j] = 255;
            else
            image[i][j] = 0;

    }
  }
  detect_edge();
}
