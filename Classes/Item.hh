<?hh //strict

class Item {

    public int $amount;

    public string $code;
    
    private mixed $rule;
    
    public function __construct (string $code, mixed $rule) {
        $this->code = $code;
        $this->amount = 1;
        $this->rule = $rule;
    }

    public function getPrice () : float {
        $price = (float)0.0;
        $discounted_amount_tot = 0;
        $amount = $this->amount;

        if (property_exists($this->rule, "discount_amount")) {
             $discounted_amount_tot = floor($this->amount / $this->rule->discount_amount);

             if ( $discounted_amount_tot > 0 ) {
                $amount -= ($discounted_amount_tot * $this->rule->discount_amount);
                if ($this->rule->discount_price) {
                    $price += $discounted_amount_tot * $this->rule->discount_price;
                }
                //TODO percentage discount
             }
        }

        $price += $amount * ((float)$this->rule->unit_price);
        
        return $price;
    }
}