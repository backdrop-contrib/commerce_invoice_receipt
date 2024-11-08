Commerce Invoice Receipt
======================

Provides an additional 'Invoice' display for Commerce orders, as well as a Rules action to email this invoice out to customers.The HTML email can be customised through template files.

Requirements
------------

This module requires that the following modules are also enabled:

 * [Commerce](https://github.com/backdrop-contrib/commerce)
 * [Emogrifier](https://github.com/backdrop-contrib/emogrifier)

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.

- Setup new Commerce Order display under Store -> Configuration -> Order Settings -> Manage Display '?q=admin/commerce/config/order/display'. Click on the 'Invoice/Receipt' tab. Unhide any fields you want to use in your invoice.

- Setup a rule under Store -> Configuration -> Checkout settings -> Checkout rules '?q=admin/commerce/config/checkout/rules'. Then 'Add a checkout rule', you'll find an action called 'Send invoice receipt email' under Commerce Order that you can use.


Documentation
-------------

Additional documentation is located in [the Wiki](https://github.com/backdrop-contrib/commerce_invoice_receipt/wiki/Documentation).

Issues 
------

Bugs and feature requests should be reported in [the Issue Queue](https://github.com/backdrop-contrib/commerce_invoice_receipt/issues).

Current Maintainers
-------------------

- [Eli Lisseck](https://github.com/elisseck).
- [Anthony Nemirovsky](https://github.com/anemirovsky).

Credits
-------

- Backdrop development supported by [USENIX](https://www.usenix.org/).
- Backdrop development supported by [Giant Rabbit](https://giantrabbit.com).
- Ported to Backdrop CMS by [Anna Heath](https://github.com/aheath),[Lauren Blais](https://github.com/rlblais)
- Porting to Backdrop CMS development sponsored by [USENIX](https://www.usenix.org/).
- Originally written for Drupal by [
(jdelaune)
](https://www.drupal.org/u/jdelaune).
- Drupal 7 version co-maintained by:
  - [Aram Boyajyan (aramboyajyan)](https://www.drupal.org/u/aramboyajyan)
  - [Jamil Daglees (Daglees)](https://www.drupal.org/u/daglees)
  - [antoniotorres](https://www.drupal.org/u/antoniotorres)

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.

