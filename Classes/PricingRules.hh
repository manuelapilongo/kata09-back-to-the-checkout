<?hh //strict

class PricingRules {

    private string $pricing_rules_path;

    private mixed $pricing_rules;

    public function __construct (string $pricing_rules_path) {

        $this->pricing_rules_path = $pricing_rules_path;

        //printInfo("Loading Rules File: ".$pricing_rules_path);

        $this->pricing_rules = json_decode(file_get_contents($pricing_rules_path));
    }

    public function getRule (string $item) : mixed {
    	return $this->pricing_rules->{$item};
    }
}
