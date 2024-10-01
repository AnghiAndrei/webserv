#ifndef WEBSERV_HPP
#define WEBSERV_HPP
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/stat.h>
#include<algorithm>
#include<unistd.h>
#include<signal.h>
#include<dirent.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<fcntl.h>
#include<string>
#include<vector>
#include<poll.h>
#include<ctime>
#include<map>

#define EXECUTION_TIME_LIMIT 20
#define BUFFER_SIZE1 1
#define BUFFER_SIZE 16384

class server;
class webserv;
class location;
struct t_master;

t_master read_file(std::string &locate, std::string &filePath, int fdc, server &server, char **env, std::string &query_get, std::string &query_post);
t_master execute(std::string &locate, int fdc, server &server, const std::string &request, char **env, std::string &get_query, std::string &post_query);
bool endsWith(const std::string &str, const std::string &suffix);
std::string ExtractFile(const std::string &directoryPath);
std::string ExtractPath(const std::string &directoryPath);
std::string ft_strtrim(std::string s1, std::string set);
unsigned long long int stoull(const std::string &str);
int check(int argc, char **argv, webserv *webservv);
std::string readFile(const std::string &filePath);
std::string getext(const std::string &path);
std::string ExtensionFile(std::string name);
bool dirExists(const std::string &path);
bool fileExists(const char *path);
void printWebserv(webserv &ws);
int setnblocking(int socket);

struct t_master{
	std::string content;
	int status;
};

class location{
	private:
		std::vector<std::string> med_allow;
		std::vector<std::string> ridirect;
		std::string body_size;
		std::string showdir;
		std::string index;
		std::string root;

	public:
		std::map<std::string, std::string> gci;

		~location();
		location();

		void set_body_size(std::string copy);
		void set_showdir(std::string copy);
		void set_index(std::string copy);
		void set_root(std::string copy);
		std::string get_root();
		std::string get_index();
		std::string get_showdir();
		std::string get_body_size();

		void set_medallow(std::vector<std::string> copy);
		std::string get_medallow(size_t index);
		size_t get_lmedallow();
		bool is_allow_metod(std::string metod);

		void set_ridirect(std::vector<std::string> copy);
		std::string get_ridirect(size_t index);
		size_t get_lridirect();
};

class server{
	private:
		std::string name_server;
		std::string error404;
		std::string error405;
		std::string error418;
		std::string error413;
		std::string error500;
		int socketserverfd;
		std::string host;
		int port;

	public:
		std::map<std::string, location> locations;
		std::map<std::string, std::string> gci;

		server(webserv &master);
		~server();

		void set_error404(std::string &copy);
		void set_error405(std::string &copy);
		void set_error418(std::string &copy);
		void set_error413(std::string &copy);
		void set_error500(std::string &copy);
		void set_name(std::string &copy);
		void set_host(std::string &copy);
		void set_port(int copy);
		int get_port();
		std::string get_host();
		int get_fd();
		std::string get_name();
		std::string get_error500();
		std::string get_error418();
		std::string get_error413();
		std::string get_error404();
		std::string get_error405();

		void start();
};

class webserv{
	size_t nserv;
	public:
		std::vector<server> servers;

		void create_server();
		size_t	get_n_server();
		void set_nserv(size_t serv);
		webserv();
		~webserv();
};
#endif