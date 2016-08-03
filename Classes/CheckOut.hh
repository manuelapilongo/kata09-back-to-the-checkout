<?hh //strict

class CheckOut {

    public float $total;

    private PricingRules $curr_rules;

    private array<string, Item> $items;

    public function __construct(PricingRules $default_pricing_rules) : void {
        $this->setTotal(0.0);
        $this->items = array();
        $this->curr_rules = $default_pricing_rules;
    }

    private function setTotal (float $new_total) : void {
        $this->total = $new_total;
    }

    private function recalcTotal () : void {
        $this->total = 0.0;
        foreach ($this->items as $item => &$item_group) {
            $this->total += $item_group->getPrice();
        }
    }

    public function emptyCart () : CheckOut {
        $this->items = array();
        $this->setTotal(0.0);
        return $this;
    }

    public function setRule (PricingRules $rule) : CheckOut {
        $this->curr_rules = $rule;
        return $this;
    }

    public function scan (string $item) : CheckOut {
        if (isset($item) && strlen($item) > 0) {
            if (!array_key_exists($item, $this->items)) {
                $this->items[$item] = new Item($item, $this->curr_rules->getRule($item));
                ///printInfo("New Scanned Item: ".$item);
            } else {
                $this->items[$item]->amount++;
                //printInfo("Updated Scanned Item Amount: ".((string) $this->items[$item]->amount));
            }
            $this->recalcTotal();
	}
	return $this;
    }
}
