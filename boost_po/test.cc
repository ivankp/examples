#include <iostream>
#include <vector>
#include <string>

#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char **argv)
{
  vector<string> arg_a;
  string arg_b, conf_fname;

  // options ---------------------------------------------------
  try {
    po::options_description desc("Options");
    desc.add_options()
      ("group.a,a", po::value(&arg_a)->multitoken()->required(),
       "a's")
      ("group.b,b", po::value(&arg_b)->default_value("default string"),
       "b's")
      ("conf,c", po::value(&conf_fname),
       "configuration file")
    ;

    po::positional_options_description pos;
    pos.add("conf",1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv)
      .options(desc).positional(pos).run(), vm);
    if (argc == 1) {
      cout << desc << endl;
      return 0;
    }
    if (vm.count("conf")) {
      po::store( po::parse_config_file<char>(
        vm["conf"].as<string>().c_str(), desc), vm);
    }
    po::notify(vm);
  } catch (exception& e) {
    cerr << "\033[31m" << argv[0]
         << " options: " <<  e.what() <<"\033[0m"<< endl;
    return 1;
  }
  // end options ---------------------------------------------------

  if (conf_fname.size()) cout << "Config file: " << conf_fname << endl;
  for (auto& a : arg_a) cout << "a: " << a << endl;
  cout << "b: " << arg_b << endl;

  return 0;
}
