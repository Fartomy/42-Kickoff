#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( string target ) : Form( target, 137, 145 ) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::execute( const Bureaucrat &obj )
{
	if ( getExecGrade() < obj.getGrade() )
		throw GradeTooLowException();
	if ( getIsSigned() == false )
		throw NotSignedException();
	exeAction();
}

void ShrubberyCreationForm::exeAction( void )
{
	string str = getName() + "_shrubbery";
	ofstream file( str.c_str() );
	file << "                C++ " << endl;
	file << "               \\_/ " << endl;
	file << "                 | " << endl;
	file << "                 * " << endl;
	file << "                *** " << endl;
	file << "               ***** " << endl;
	file << "              ***|*** " << endl;
	file << "             ****O**** " << endl;
	file << "            *********** " << endl;
	file << "           ***|***|***** " << endl;
	file << "          ****$***|**|*** " << endl;
	file << "         **|******O**+**** " << endl;
	file << "        ***@*****|********* " << endl;
	file << "       ****|*****@******|*** " << endl;
	file << "      **|**+************$**** " << endl;
	file << "     ***|*****|***|***|****|** " << endl;
	file << "    ****$*****|***O***|****@*** " << endl;
	file << "   ***********+*******+********* " << endl;
	file << "  **|**|**|*###########**|*|**|** " << endl;
	file << "    |  |  | ###########  | |  |    " << endl;
	file << "    $  |  | ###########  | |  O    " << endl;
	file << "       |  | ###########  $ |       " << endl;
	file << "       |  O ###########    |       " << endl;
	file << "       @    ###########    +       " << endl;
	file << "            ###########            " << endl;
	file << "           #############           " << endl;
	file << "          ###############          " << endl;
	file << "_O__+_@__#################__$_+_@__" << endl;
	file.close();
	cout << str << " File is created!" << endl;
}