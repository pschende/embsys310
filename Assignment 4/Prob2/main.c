void func1(int dude1, int dude2, int dude3, int dude4, int dude5){
  int mandrake = 1;
  mandrake++;
}
void func2(void){
  func1(10, 20, 30, 40, 50);
}

void main(void)
{
  func2();
}