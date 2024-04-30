#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  ifstream file("coordinates.txt");
  string line;

  if (!file.is_open())
  {
    cerr << "Ошибка файла!" << endl;
    return 1;
  }

  while (getline(file, line))
  {
    istringstream iss(line);
    double latitude, longitude;
    char delimiter;

    if (!(iss >> delimiter >> latitude >> delimiter >> longitude >> delimiter) || delimiter != ')')
    {
      cerr << "Ошибка при разборе строки: " << line << endl;
      continue;
    }

    // Проверяем, находятся ли координаты в указанных пределах
    if (latitude >= 50 && latitude <= 80 && longitude >= 20 && longitude <= 45)
    {
      cout << "(" << latitude << ", " << longitude << ")" << endl;
    }
  }

  file.close();
  return 0;
}
