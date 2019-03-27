#include <stdexcept>
using namespace std;
class bestand_niet_lang_genoeg : public invalid_argument {
   public:
    bestand_niet_lang_genoeg(const string &file = "", int r = 0) : invalid_argument("bestand \"" + file + "\" heeft geen " + to_string(r) + " regels \n") {}
};