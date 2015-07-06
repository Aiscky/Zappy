//
// ia.cpp for ia.cpp in /home/boutet_a/ZAPPY_TESTS
// 
// Made by Mehdi Boutet
// Login   <boutet_a@epitech.net>
// 
// Started on  Wed Jun 17 14:04:48 2015 Mehdi Boutet
// Last update Sun Jul  5 23:17:50 2015 manin dylan
//

#include		"../include/Ia.hh"

Ia::Ia(NetworkClient *network, std::string teamname)
{
  _network = network;
  _needlvlup = false;
  _lvl = 1;
  _alive = true;
  _name = teamname + "\n";
  _answer = "";
  _where = 0;
  _checkedDirections = 0;
}

Ia::~Ia()
{
  delete(_network);
}

bool                            Ia::setConnection() {
  if (_network->Connect())
    return (true);
  return (false);
}

int								Ia::handlerMsg(std::string msg)
{
  if (msg.find("lvlup") != std::string::npos) {
    std::string tmp = msg.substr(8);
    tmp = tmp.substr(0, tmp.find(",") - 1);
    std::istringstream ss(tmp);
    ss >> _where;
    return (1);
  }
  // gerer les inventaire des autres
}

std::vector<std::string>        Ia::my_getobjective()
{
  std::ifstream                 file("client_src/lvls.zap");
  int                           nb1, nb2;
  std::string                   chaine1;
  std::vector<std::string>      stock;

  if (file)
    {
      file >> nb1 >> nb2;
      while (nb1 != _lvl + 1)
	{
	  file >> chaine1;
	  while (chaine1 != ".")
	    file >> chaine1;
	  file >> nb1 >> nb2;
	}
      _nb_up = nb2;
      file >> chaine1;
      while (chaine1 != ".")
	{
	  stock.push_back(chaine1);
	  file >> chaine1;
	}
      file.close();
      return (stock);
    }
  else
    std::cerr << "Problem occured while loading file \"lvls.zap\"" << std::endl;
}

std::string                     Ia::my_getobj(std::string view, std::size_t mul_pos, std::size_t pos)
{
  std::string                   stock;
  int                           i;

  if (pos < mul_pos)
    mul_pos = pos;
  stock = view.substr(0, mul_pos);
  if (stock[stock.size()] == ' ' || stock[stock.size()] == ',')
    stock = stock.substr(0, stock.size() - 1);
  return (stock);
}

int                             Ia::my_findmatch(std::string stock, std::vector<std::string> target)
{
  int                           i;

  i = 0;
  while (i < target.size())
    {
      if (target[i] == stock)
	return (i);
      i++;
    }
  return (-1);
}

void                            Ia::my_goto(int coma)
{
  if (coma > 0)
    {
      int x;
      int y;
      int posY = 1;
      int destination;

      y = 0;
      while (coma + 1 > getVisualRange(y)) {
	y++;
      }
      x = coma - (y == 0 ? getVisualRange(0) : getVisualRange(y - 1)) - y;
      while (y != 0) {
	SendAndWait("avance\n", "ok");
	y--;
      }
      if (x > 0)
	SendAndWait("droite\n", "ok");
      if (x < 0)
	SendAndWait("gauche\n", "ok");
      (x < 0  ? x = -x : 0);
      while (x != 0) {
	SendAndWait("avance\n", "ok");
	x--;
      }
      _checkedDirections = 0;
     }
}

bool				        		Ia::my_findfood(std::string food, std::string view)
{
  int                           coma;
  std::size_t                   pos;
  std::size_t                   mul_pos;
  std::string                   stock;
  int                           i;

  coma = 0;
  mul_pos = view.find(" ");
  pos = view.find(",");
  if (_food == 2)
    SendAndWait("fork\n", "ok");
  while (pos != std::string::npos && mul_pos != std::string::npos)
    {
      mul_pos = view.find(" ");
      pos = view.find(",");
      if (pos < mul_pos)
	{
	  coma++;
	  view = view.substr(pos + 1);
	}
      else
	{
	  while (mul_pos < pos)
	    {
	      view = view.substr(mul_pos + 1);
	      mul_pos = view.find(" ");
	      stock = this->my_getobj(view, mul_pos, pos);
	      if (stock.find("nourriture") != stock.npos) {
		my_goto(coma);
		SendAndWait("prend nourriture\n", "ok/ko");
		return (true);
	      }
	      pos = view.find(",");
	    }
	}
    }
  return (false);
}

bool						      Ia::my_findrocks(std::vector<std::string> &target, std::string view)
{
  std::vector<std::string>				*cases;
  std::vector<std::string>				*sub;
  int							i;
  int							j;
  int							size;
  int							nb;
  int							where;

  view = view.substr(2);
  view = view.substr(0, view.size() - 1);
  cases = Utils::split(view, ",");
  size = cases->size();
  i = 0;
  while (i <= size && !target.empty())
    {
      nb = 0;
      sub = Utils::split((*cases)[i], " ");
      j = sub->size();
      while (nb <= j)
	{
	  if ((where = this->my_findmatch((*sub)[nb], target)) >= 0)
	    {
	      this->my_goto(i);
	      SendAndWait("prend " + target[where] + "\n", "ok/ko");
	      if (_answer == "ok") {
		_inv.push_back(target[where]);
		target.erase(target.begin() + where);
	      }
	      return (true);
	    }
	  nb++;
	}
      i++;
    }
  return (false);
}

int                             Ia::my_getfood()
{
  std::string			inv;
  int                           food;
  int                           i;
  int                           j;

  SendAndWait("inventaire\n", "{");
  inv = _answer;
  i = inv.find("nourriture");
  inv = inv.substr(i);
  i = inv.find(" ");
  i++;
  j = inv.find(",");
  j = j - i;
  inv = inv.substr(i, j);
  std::istringstream ss(inv);
  ss >> food;
  return (food);
}

void                            Ia::my_axis(int i)
{
  if (i == 3)
    SendAndWait("gauche\n", "ok");
  else if (i == 5 || i == 7)
    {
      SendAndWait("droite\n", "ok");
      if (i == 5)
	SendAndWait("droite\n", "ok");
      SendAndWait("avance\n", "ok");
    }
  SendAndWait("avance\n", "ok");
}

void                            Ia::my_diago(int i)
{
  if (i == 2)
    {
      SendAndWait("avance\n", "ok");
      SendAndWait("gauche\n", "ok");
      SendAndWait("avance\n", "ok");
      SendAndWait("droite\n", "ok");
    }
  else if (i == 8)
    {
      SendAndWait("avance\n", "ok");
      SendAndWait("droite\n", "ok");
      SendAndWait("avance\n", "ok");
      SendAndWait("gauche\n", "ok");
    }
  else
    {
      SendAndWait("gauche\n", "ok");
      SendAndWait("gauche\n", "ok");
      SendAndWait("avance\n", "ok");
    }
}


int                             Ia::check_broad(std::string broad)
{
  if (broad.find("message") != std::string::npos && broad.find("lvlup") != std::string::npos)
    return (1);
  else
    return (0);
}


void                            Ia::my_lvlup()
{                                                                               
  std::string                   broad = "message 3,lvlup\n";
  char                          stock;
  int                           i;

  i = 1;
  if (this->check_broad(broad) == 1)
    {
      while (i != 0 && (this->check_broad(broad)) == 1)
	{
	  i = broad.find(" ");
	  stock = broad[i + 1];
	  i = stock - 48;
	  if (i != 0)
	    {
	      if (i % 2 == 0)
		this->my_diago(i);
	      else
		this->my_axis(i);
	    }
	}
    }
  if (i != 0)
    this->my_lvlup();
  while (this->_nb_up > i)
    {
      i = this->check_players(broad);
    }
  this->my_putrocks();
}                                                                               

void                            Ia::my_putrocks()
{
  std::vector<std::string>      rocks;
  int                           i;
  int                           j;

  i = _inv.size();
  rocks = my_getobjective();
  j = rocks.size();
  while (!rocks.empty() || (j == 0 && i == 0))
    {
      if (_inv[i] == rocks[j])
	{
	  SendAndWait("pose " + _inv[i], "ok/ko");
	  _inv.erase(_inv.begin() + i);
	  rocks.erase(rocks.begin() + j);
	  i = _inv.size();
	  j = rocks.size();
	}
      else if (i == 0)
	{
	  i = _inv.size();
	  j--;
	}
      else
	i--;
    }
}

int                             Ia::check_players(std::string view)
{
  int                           i;
  int                           nb;

  view.find(",");
  view.substr(1, i);
  nb = 0;
  while ((i = view.find("joueur")) != std::string::npos)
    {
      nb++;
    }
  return (nb);
}

void							Ia::setIdMap()
{
  std::vector<std::string>	*tmp = new std::vector<std::string>;

  while (tmp->size() < 3) {
    std::vector<std::string>	*tmp2 = _network->Select();
    tmp->insert( tmp->end(), tmp2->begin(), tmp2->end());
  }
  std::istringstream ss((*tmp)[1]);
  ss >> _id;
  std::vector<std::string>	*map;
  map = Utils::split((*tmp)[2], " ");
  std::istringstream x((*map)[0]);
  std::istringstream y((*map)[1]);
  x >> _x;
  y >> _y;
}

int								Ia::loopReply(std::vector<std::string> *reply, std::string ans)
{
  int					end = 0;
  for (unsigned int i = 0; i < reply->size(); i++) {
    if ((*reply)[i] == "mort")
      exit(0);
    if (((*reply)[i]).find("niveau actuel") != std::string::npos) {
      std::string tmp = ((*reply)[i]).substr(16);
      std::istringstream ss(tmp);
      ss >> _lvl;
    }
    if ( (*reply)[i].find("message") != std::string::npos) {
      if (handlerMsg((*reply)[i]) > 0)
	_needlvlup = true;
    }
    if ( (*reply)[i].find(ans) != std::string::npos) {
      _answer = (*reply)[i];
      end = 1;
    }
  }
  if (end == 1)
    return (1);
  return (0);
}

void							Ia::SendAndWait(std::string cmd, std::string ans)
{
  std::vector<std::string>	        *reply = new std::vector<std::string>;
  int					end = 0;

  if (cmd.find("lvlup") != std::string::npos) {
    reply = _network->Select();
    loopReply(reply, ans);
    if (_needlvlup == true) {
      ;
      return ;
    }
  }
  _network->Send(cmd);
  while (end == 0) {
    reply = _network->Select();
    end = loopReply(reply, ans);
  }
}

int								Ia::getVisualRange(int level) {
  int							visualRange = 0;

  for (int i = 0; i <= level; ++i) {
    visualRange += i * 2 + 1;
  }
  return (visualRange);
}

void							Ia::run() {
  std::vector<std::string>	target;
  std::string					view;

  _network->Send(_name);
  setIdMap();
  while (_alive) {
    target = my_getobjective();
    while (target.size() > 0)
      {
	_food = my_getfood();
	SendAndWait("voir\n", "{");
	view = _answer;
	my_findfood("nourriture", _answer);
	if (_checkedDirections != 4) {
	  SendAndWait("droite\n", "ok");
	  _checkedDirections += 1;
	}
	else {
	  my_goto(getVisualRange(_lvl) + _lvl + 1);
	  my_goto(getVisualRange(_lvl) + _lvl + 1);
	}
      }
    _lvl++;
  }
}
