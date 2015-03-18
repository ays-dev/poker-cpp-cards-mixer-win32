# poker-cpp-cards-mixer-win32
Quick example for mixing cards of a poker set using dSFMT and calling the Windows cryptographic service provider (CSP) by leveraging the wincrypt api in C++

Following same recommendations as PKR.fr (see here: http://www.pkr.fr/fr/support/licensing-and-integrity/monthly-certificates/ )


What is SFMT?
SFMT is a new variant of Mersenne Twister (MT) introduced by Mutsuo Saito and Makoto Matsumoto in 2006.

What is dSFMT?
Double precision SIMD-oriented Fast Mersenne Twister (dSFMT)
The purpose of dSFMT is to speed up the generation by avoiding the expensive conversion of integer to double (floating point). dSFMT directly generates double precision floating point pseudorandom numbers which have the IEEE Standard for Binary Floating-Point Arithmetic (ANSI/IEEE Std 754-1985) format. dSFMT is only available on the CPUs which use IEEE 754 format double precision floating point numbers. 

See dSFMT doc: http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/#dSFMT


What is cryptographic service provider (CSP)?
An independent software module that actually performs cryptography algorithms for authentication, encoding, and encryption.

See windows cryptographic service doc: https://msdn.microsoft.com/en-us/library/windows/desktop/ms721572%28v=vs.85%29.aspx#_security_cryptographic_service_provider_gly

see CryptGenRandom function doc: https://msdn.microsoft.com/en-us/library/windows/desktop/aa379942%28v=vs.85%29.aspx