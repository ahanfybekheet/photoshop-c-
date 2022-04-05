void mirror_first_col() {

  int x=0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

            if(j>(SIZE/2)){

                image[i][j]=image[i][(SIZE/2)-x];
                x++;
            }

    }
    x=0;
  }

}
void mirror_second_col() {

  int x=0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

            if(j<(SIZE/2)){

                image[i][j]=image[i][SIZE-x];
                x++;
            }

    }
    x=0;
  }

}

void mirror_second_row() {

  int x=0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

            if(i<(SIZE/2)){

                image[i][j]=image[SIZE-x][j];

            }

    }
    x++;
  }

}

void mirror_first_row() {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

            if(i>(SIZE/2)){

                image[i][j]=image[SIZE-i][j];

            }

    }
  }

}
