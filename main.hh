<?hh //strict

require("init.hh");

function price (string $goods) : float {
    $co = new CheckOut(new PricingRules(Kata09."/Json/rules.json"));

    foreach (str_split($goods) as $item_code) {
	$co->scan($item_code);
    }

    $co_total = $co->total;

    return $co_total;
}

function assert_equal (float $exp, float $act, string $msg = "") : void {
    $result = ($exp === $act) ? "PASSED" : "FAIL";
    printInfo("TEST " . $msg . $result);
}

function test_totals () : void {
    assert_equal(  0.0, price(""));
    assert_equal( 50.0, price("A"));
    assert_equal( 80.0, price("AB"));
    assert_equal(115.0, price("CDBA"));

    assert_equal(100.0, price("AA"));
    assert_equal(130.0, price("AAA"));
    assert_equal(180.0, price("AAAA"));
    assert_equal(230.0, price("AAAAA"));
    assert_equal(260.0, price("AAAAAA"));

    assert_equal(160.0, price("AAAB"));
    assert_equal(175.0, price("AAABB"));
    assert_equal(190.0, price("AAABBD"));
    assert_equal(190.0, price("DABABA"));
}

function test_incremental () : void {
    $co = new CheckOut(new PricingRules(Kata09."/Json/rules.json"));
    assert_equal(  0.0, $co->total);
    $co->scan("A");  assert_equal( 50.0, $co->total);
    $co->scan("B");  assert_equal( 80.0, $co->total);
    $co->scan("A");  assert_equal(130.0, $co->total);
    $co->scan("A");  assert_equal(160.0, $co->total);
    $co->scan("B");  assert_equal(175.0, $co->total);
}


function main() : void {
    test_totals();
    test_incremental();
}

main();
