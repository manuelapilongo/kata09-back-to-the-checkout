<?hh //strict

//debug function
function printInfo (string $info, bool $add_eol = TRUE) : void {
	echo $info . ($add_eol ? PHP_EOL : "");
}

//working directory
const string Kata09 = __DIR__;//realpath(dirname(__FILE__));

require(Kata09."/Classes/PricingRules.hh");
require(Kata09."/Classes/CheckOut.hh");
require(Kata09."/Classes/Item.hh");
