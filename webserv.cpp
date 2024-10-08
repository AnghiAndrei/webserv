#include"webserv.hpp"

/* ====== LOCATION ====== */
location::~location(){}
location::location(){
    root="";
    index="";
    showdir="yes";
    body_size="-1";
}

void location::set_body_size(std::string copy){body_size=copy;}
void location::set_showdir(std::string copy){showdir=copy;}
void location::set_index(std::string copy){index=copy;}
void location::set_root(std::string copy){root=copy;}
std::string location::get_root(){return root;}
std::string location::get_index(){return index;}
std::string location::get_showdir(){return showdir;}
std::string location::get_body_size(){return body_size;}

void location::set_medallow(std::vector<std::string> copy){this->med_allow.insert(med_allow.begin(), copy.begin(), copy.end());}
std::string location::get_medallow(size_t index){return med_allow[index];}
size_t location::get_lmedallow(){return med_allow.size();}
bool location::is_allow_metod(std::string metod){
    std::vector<std::string>::iterator temp=std::find(med_allow.begin(), med_allow.end(), metod);
    if(temp!=med_allow.end())
        return true;
    return false;
}

void location::set_ridirect(std::vector<std::string> copy){this->ridirect.insert(ridirect.begin(), copy.begin(), copy.end());}
std::string location::get_ridirect(size_t index){return ridirect[index];}
size_t location::get_lridirect(){return ridirect.size();}

/* ====== SERVER ====== */
server::~server(){/*close(socketserverfd);*/}
server::server(webserv &master){
    std::ostringstream cy;
    cy << master.get_n_server() + 1;
	error404="./dsite/404.html";
	error405="./dsite/405.html";
	error418="./dsite/418.html";
	error413="./dsite/413.html";
	error500="./dsite/500.html";
    name_server=("Server"+cy.str());
    host="";
    port=-1;
}

void server::set_error404(std::string &copy){error404=copy;}
void server::set_error405(std::string &copy){error405=copy;}
void server::set_error418(std::string &copy){error418=copy;}
void server::set_error413(std::string &copy){error413=copy;}
void server::set_error500(std::string &copy){error500=copy;}
void server::set_name(std::string &copy){name_server=copy;}
void server::set_host(std::string &copy){host=copy;}
void server::set_port(int copy){port=copy;}
int server::get_port(){return port;}
std::string server::get_host(){return host;}
int server::get_fd(){return socketserverfd;}
std::string server::get_name(){return name_server;}
std::string server::get_error500(){return error500;}
std::string server::get_error418(){return error418;}
std::string server::get_error413(){return error413;}
std::string server::get_error404(){return error404;}
std::string server::get_error405(){return error405;}

void server::start(){
    struct sockaddr_in address;
    int opt = 1;

    if((socketserverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cout<<"Marshal: Socket failed"<<std::endl;
        exit(-1);
    }
    if(setsockopt(socketserverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cout<<"Marshal: Setsockopt failed"<<std::endl;
        exit(-1);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if(bind(socketserverfd, (struct sockaddr *)&address, sizeof(address))<0){
        std::cout<<"Marshal: Bind failed"<<std::endl;
        exit(-1);
    }
    if(listen(socketserverfd, 3)<0){
        std::cout<<"Marshal: Listen failed"<<std::endl;
        exit(-1);
    }
    setnblocking(socketserverfd);
}

/* ====== WEBSERV ====== */
void webserv::create_server(){servers.push_back(server(*this));}
size_t	webserv::get_n_server(){return servers.size();}
void webserv::set_nserv(size_t serv){this->nserv=serv;}
webserv::webserv(){nserv=0;}
webserv::~webserv(){}