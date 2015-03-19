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
To form the seed for the random number generator, a calling application supplies bits it might have—for instance, mouse or keyboard timing input—that are then combined with both the stored seed and various system data and user data such as the process ID and thread ID, the system clock, the system time, the system counter, memory status, free disk clusters, the hashed user environment block. This result is used to seed the pseudorandom number generator (PRNG)

See windows cryptographic service doc: https://msdn.microsoft.com/en-us/library/windows/desktop/ms721572%28v=vs.85%29.aspx#_security_cryptographic_service_provider_gly

see CryptGenRandom function doc: https://msdn.microsoft.com/en-us/library/windows/desktop/aa379942%28v=vs.85%29.aspx