#include <openssl/bn.h>

int main()
{
  // a just instantiated BIGNUM is initialized to 0
  BIGNUM *b1=BN_new();
  BIGNUM *b2=BN_new();
  BIGNUM *b3=BN_new();


  // print after init
  BN_print_fp(stdout,b3);
  printf("\n");

  // roughly speaking: _word functions mean -> from unsigned long
  BN_set_word(b1,354);
  BN_set_word(b2,75);

  // b1 % b2 --> b3
  // you can see a context as  a sort of scratchpad where
  // the operations on BIGNUM take notes
  // you need one to operate
  BN_CTX *ctx=BN_CTX_new();
  
  BN_mod(b3,b1,b2,ctx);

  // print in hex format
  BN_print_fp(stdout,b3);
  printf("\n");


  BN_free(b1);
  BN_free(b2);
  BN_free(b3);

  BN_CTX_free(ctx);

  return 0;
}
