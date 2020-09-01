#include <iostream>

class Friends {
protected:
  std::string Name;

  
public:
  Friends();
  virtual ~Friends();

  virtual void CallYourName(Friends &f);

  friend std::string getName(Friends &);
};

Friends::Friends(){}
Friends::~Friends(){}

std::string getName(Friends &obj) {
  return obj.Name;
}

void Friends::CallYourName(Friends &f)
{}

class Bag;

class Serval : public Friends {

private:
  void Mogmog();
  
public:
  Serval();
  ~Serval();

  void CallYourName(Friends &f);
  
  friend Bag;
};

Serval::Serval() {
  Name = "サーバル";
}

Serval::~Serval() {
  
}

void Serval::Mogmog()
{
  std::cout << "mog mog" << std::endl;
}

void Serval::CallYourName(Friends &f)
{

  auto name = getName(f);

  if(name == "カバン")
    name += "ちゃん";
  
  std::cout << name << std::endl;


}

class Bag : public Friends {

private:
  int nameSize();


  
public:
  Bag();
  ~Bag();

  void CallYourName(Friends &obj);

  void How(Serval &s);

  friend Serval;
};

Bag::Bag() {
  Name = "カバン";
}

Bag::~Bag(){}

void Bag::How(Serval &s)
{
  s.Mogmog();
}

void Bag::CallYourName(Friends &obj)
{

  auto str = getName(obj);

  if(str == "サーバル")
    str += "ちゃん";
  
  std::cout << str << std::endl;
}

int main() {
  auto serval = Serval();

  // auto str = getName(obj);

  std::cout << getName(serval) << std::endl;
  
  auto kaban = Bag();
  kaban.CallYourName(serval);
  kaban.How(serval);

  serval.CallYourName(kaban);




}
