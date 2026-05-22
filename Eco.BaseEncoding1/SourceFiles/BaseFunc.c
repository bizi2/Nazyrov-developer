#include "BaseFunc.h"

#define B16(_)					\
  ((_) == '0' ? 0				\
   : (_) == '1' ? 1				\
   : (_) == '2' ? 2				\
   : (_) == '3' ? 3				\
   : (_) == '4' ? 4				\
   : (_) == '5' ? 5				\
   : (_) == '6' ? 6				\
   : (_) == '7' ? 7				\
   : (_) == '8' ? 8				\
   : (_) == '9' ? 9				\
   : (_) == 'A' ? 10				\
   : (_) == 'B' ? 11				\
   : (_) == 'C' ? 12				\
   : (_) == 'D' ? 13				\
   : (_) == 'E' ? 14				\
   : (_) == 'F' ? 15				\
   : -1)

#define B32(_)					\
  ((_) == 'A' ? 0				\
   : (_) == 'B' ? 1				\
   : (_) == 'C' ? 2				\
   : (_) == 'D' ? 3				\
   : (_) == 'E' ? 4				\
   : (_) == 'F' ? 5				\
   : (_) == 'G' ? 6				\
   : (_) == 'H' ? 7				\
   : (_) == 'I' ? 8				\
   : (_) == 'J' ? 9				\
   : (_) == 'K' ? 10				\
   : (_) == 'L' ? 11				\
   : (_) == 'M' ? 12				\
   : (_) == 'N' ? 13				\
   : (_) == 'O' ? 14				\
   : (_) == 'P' ? 15				\
   : (_) == 'Q' ? 16				\
   : (_) == 'R' ? 17				\
   : (_) == 'S' ? 18				\
   : (_) == 'T' ? 19				\
   : (_) == 'U' ? 20				\
   : (_) == 'V' ? 21				\
   : (_) == 'W' ? 22				\
   : (_) == 'X' ? 23				\
   : (_) == 'Y' ? 24				\
   : (_) == 'Z' ? 25				\
   : (_) == '2' ? 26				\
   : (_) == '3' ? 27				\
   : (_) == '4' ? 28				\
   : (_) == '5' ? 29				\
   : (_) == '6' ? 30				\
   : (_) == '7' ? 31				\
   : -1)

#define B64(_)					\
  ((_) == 'A' ? 0				\
   : (_) == 'B' ? 1				\
   : (_) == 'C' ? 2				\
   : (_) == 'D' ? 3				\
   : (_) == 'E' ? 4				\
   : (_) == 'F' ? 5				\
   : (_) == 'G' ? 6				\
   : (_) == 'H' ? 7				\
   : (_) == 'I' ? 8				\
   : (_) == 'J' ? 9				\
   : (_) == 'K' ? 10				\
   : (_) == 'L' ? 11				\
   : (_) == 'M' ? 12				\
   : (_) == 'N' ? 13				\
   : (_) == 'O' ? 14				\
   : (_) == 'P' ? 15				\
   : (_) == 'Q' ? 16				\
   : (_) == 'R' ? 17				\
   : (_) == 'S' ? 18				\
   : (_) == 'T' ? 19				\
   : (_) == 'U' ? 20				\
   : (_) == 'V' ? 21				\
   : (_) == 'W' ? 22				\
   : (_) == 'X' ? 23				\
   : (_) == 'Y' ? 24				\
   : (_) == 'Z' ? 25				\
   : (_) == 'a' ? 26				\
   : (_) == 'b' ? 27				\
   : (_) == 'c' ? 28				\
   : (_) == 'd' ? 29				\
   : (_) == 'e' ? 30				\
   : (_) == 'f' ? 31				\
   : (_) == 'g' ? 32				\
   : (_) == 'h' ? 33				\
   : (_) == 'i' ? 34				\
   : (_) == 'j' ? 35				\
   : (_) == 'k' ? 36				\
   : (_) == 'l' ? 37				\
   : (_) == 'm' ? 38				\
   : (_) == 'n' ? 39				\
   : (_) == 'o' ? 40				\
   : (_) == 'p' ? 41				\
   : (_) == 'q' ? 42				\
   : (_) == 'r' ? 43				\
   : (_) == 's' ? 44				\
   : (_) == 't' ? 45				\
   : (_) == 'u' ? 46				\
   : (_) == 'v' ? 47				\
   : (_) == 'w' ? 48				\
   : (_) == 'x' ? 49				\
   : (_) == 'y' ? 50				\
   : (_) == 'z' ? 51				\
   : (_) == '0' ? 52				\
   : (_) == '1' ? 53				\
   : (_) == '2' ? 54				\
   : (_) == '3' ? 55				\
   : (_) == '4' ? 56				\
   : (_) == '5' ? 57				\
   : (_) == '6' ? 58				\
   : (_) == '7' ? 59				\
   : (_) == '8' ? 60				\
   : (_) == '9' ? 61				\
   : (_) == '+' ? 62				\
   : (_) == '/' ? 63				\
   : -1)

static inline uint8_t fnToUchar(int8_t ch)
{
	return ch;
}

void fnBase16Encode(int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	static const uint8_t b16str[16] =
		"0123456789ABCDEF";

	while (inlen && outlen)
	{
		*out++ = b16str[(fnToUchar(in[0]) >> 4) & 0x0f];
		if (!--outlen)
			break;
		*out++ = b16str[(fnToUchar(in[0])) & 0x0f];
		if (!--outlen)
			break;

		if (inlen)
			inlen--;
		if (inlen)
			in += 1;
	}

	if (outlen) {
		*out = '\0';
	}
}

void fnBase32Encode(int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	static const uint8_t b32str[32] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

	while (inlen && outlen)
	{
		*out++ = b32str[(fnToUchar(in[0]) >> 3) & 0x1f];
		if (!--outlen)
			break;
		*out++ = b32str[((fnToUchar(in[0]) << 2)
			+ (--inlen ? fnToUchar(in[1]) >> 6 : 0))
			& 0x1f];
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[(fnToUchar(in[1]) >> 1) & 0x1f] : '=';
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[((fnToUchar(in[1]) << 4)
			+ (--inlen ? fnToUchar(in[2]) >> 4 : 0))
			& 0x1f] : '=';
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[((fnToUchar(in[2]) << 1)
			+ (--inlen ? fnToUchar(in[3]) >> 7 : 0))
			& 0x1f] : '=';
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[(fnToUchar(in[3]) >> 2) & 0x1f] : '=';
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[((fnToUchar(in[3]) << 3)
			+ (--inlen ? fnToUchar(in[3]) >> 5 : 0))
			& 0x1f] : '=';
		if (!--outlen)
			break;
		*out++ = inlen ? b32str[fnToUchar(in[4]) & 0x1f] : '=';
		if (!--outlen)
			break;

		if (inlen)
			inlen--;
		if (inlen)
			in += 5;	
	}

	if (outlen) {
		*out = '\0';
	}
}

void fnBase64Encode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	static const uint8_t b64str[64] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	while (inlen && outlen)
	{
		*out++ = b64str[(fnToUchar(in[0]) >> 2) & 0x3f];
		if (!--outlen)
			break;
		*out++ = b64str[((fnToUchar(in[0]) << 4)
			+ (--inlen ? fnToUchar(in[1]) >> 4 : 0))
			& 0x3f];
		if (!--outlen)
			break;
		*out++ =
			(inlen
				? b64str[((fnToUchar(in[1]) << 2)
					+ (--inlen ? fnToUchar(in[2]) >> 6 : 0))
				& 0x3f]
				: '=');
		if (!--outlen)
			break;
		*out++ = inlen ? b64str[fnToUchar(in[2]) & 0x3f] : '=';
		if (!--outlen)
			break;
		if (inlen)
			inlen--;
		if (inlen)
			in += 3;
	}

	if (outlen)
		*out = '\0';
}

void* fnBase16EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t outl = 1 + BASE16_LENGTH_ENCODE(inl);

	if (inl > outl)
	{
		out = NULL;
		return 0;
	}

	out = malloc(outl);
	memset(out, 0, outl);
	if (!out)
		return outl;

	*outlen = outl;
	*inlen = inl;

	return out;
}

void* fnBase32EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t outl = 1 + BASE32_LENGTH_ENCODE(inl);

	if (inl > outl)
	{
		out = NULL;
		return 0;
	}

	out = malloc(outl);
	memset(out, 0, outl);
	if (!out)
		return outl;

	*outlen = outl;
	*inlen = inl;

	return out;
}

void* fnBase64EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t outl = 1 + BASE64_LENGTH_ENCODE(inl);

	if (inl > outl)
	{
		out = NULL;
		return 0;
	}

	out = malloc(outl);
	memset(out, 0, outl);
	if (!out)
		return outl;

	*outlen = outl;
	*inlen = inl;

	return out;
}

static const int8_t b16[256] = {
B16(0), B16(1), B16(2), B16(3),
B16(4), B16(5), B16(6), B16(7),
B16(8), B16(9), B16(10), B16(11),
B16(12), B16(13), B16(14), B16(15),
B16(16), B16(17), B16(18), B16(19),
B16(20), B16(21), B16(22), B16(23),
B16(24), B16(25), B16(26), B16(27),
B16(28), B16(29), B16(30), B16(31),
B16(32), B16(33), B16(34), B16(35),
B16(36), B16(37), B16(38), B16(39),
B16(40), B16(41), B16(42), B16(43),
B16(44), B16(45), B16(46), B16(47),
B16(48), B16(49), B16(50), B16(51),
B16(52), B16(53), B16(54), B16(55),
B16(56), B16(57), B16(58), B16(59),
B16(60), B16(61), B16(62), B16(63),
B16(64), B16(65), B16(66), B16(67),
B16(68), B16(69), B16(70), B16(71),
B16(72), B16(73), B16(74), B16(75),
B16(76), B16(77), B16(78), B16(79),
B16(80), B16(81), B16(82), B16(83),
B16(84), B16(85), B16(86), B16(87),
B16(88), B16(89), B16(90), B16(91),
B16(92), B16(93), B16(94), B16(95),
B16(96), B16(97), B16(98), B16(99),
B16(100), B16(101), B16(102), B16(103),
B16(104), B16(105), B16(106), B16(107),
B16(108), B16(109), B16(110), B16(111),
B16(112), B16(113), B16(114), B16(115),
B16(116), B16(117), B16(118), B16(119),
B16(120), B16(121), B16(122), B16(123),
B16(124), B16(125), B16(126), B16(127),
B16(128), B16(129), B16(130), B16(131),
B16(132), B16(133), B16(134), B16(135),
B16(136), B16(137), B16(138), B16(139),
B16(140), B16(141), B16(142), B16(143),
B16(144), B16(145), B16(146), B16(147),
B16(148), B16(149), B16(150), B16(151),
B16(152), B16(153), B16(154), B16(155),
B16(156), B16(157), B16(158), B16(159),
B16(160), B16(161), B16(162), B16(163),
B16(164), B16(165), B16(166), B16(167),
B16(168), B16(169), B16(170), B16(171),
B16(172), B16(173), B16(174), B16(175),
B16(176), B16(177), B16(178), B16(179),
B16(180), B16(181), B16(182), B16(183),
B16(184), B16(185), B16(186), B16(187),
B16(188), B16(189), B16(190), B16(191),
B16(192), B16(193), B16(194), B16(195),
B16(196), B16(197), B16(198), B16(199),
B16(200), B16(201), B16(202), B16(203),
B16(204), B16(205), B16(206), B16(207),
B16(208), B16(209), B16(210), B16(211),
B16(212), B16(213), B16(214), B16(215),
B16(216), B16(217), B16(218), B16(219),
B16(220), B16(221), B16(222), B16(223),
B16(224), B16(225), B16(226), B16(227),
B16(228), B16(229), B16(230), B16(231),
B16(232), B16(233), B16(234), B16(235),
B16(236), B16(237), B16(238), B16(239),
B16(240), B16(241), B16(242), B16(243),
B16(244), B16(245), B16(246), B16(247),
B16(248), B16(249), B16(250), B16(251),
B16(252), B16(253), B16(254), B16(255)
};

static const int8_t b32[256] = {
 B32(0), B32(1), B32(2), B32(3),
 B32(4), B32(5), B32(6), B32(7),
 B32(8), B32(9), B32(10), B32(11),
 B32(12), B32(13), B32(14), B32(15),
 B32(16), B32(17), B32(18), B32(19),
 B32(20), B32(21), B32(22), B32(23),
 B32(24), B32(25), B32(26), B32(27),
 B32(28), B32(29), B32(30), B32(31),
 B32(32), B32(33), B32(34), B32(35),
 B32(36), B32(37), B32(38), B32(39),
 B32(40), B32(41), B32(42), B32(43),
 B32(44), B32(45), B32(46), B32(47),
 B32(48), B32(49), B32(50), B32(51),
 B32(52), B32(53), B32(54), B32(55),
 B32(56), B32(57), B32(58), B32(59),
 B32(60), B32(61), B32(62), B32(63),
 B32(64), B32(65), B32(66), B32(67),
 B32(68), B32(69), B32(70), B32(71),
 B32(72), B32(73), B32(74), B32(75),
 B32(76), B32(77), B32(78), B32(79),
 B32(80), B32(81), B32(82), B32(83),
 B32(84), B32(85), B32(86), B32(87),
 B32(88), B32(89), B32(90), B32(91),
 B32(92), B32(93), B32(94), B32(95),
 B32(96), B32(97), B32(98), B32(99),
 B32(100), B32(101), B32(102), B32(103),
 B32(104), B32(105), B32(106), B32(107),
 B32(108), B32(109), B32(110), B32(111),
 B32(112), B32(113), B32(114), B32(115),
 B32(116), B32(117), B32(118), B32(119),
 B32(120), B32(121), B32(122), B32(123),
 B32(124), B32(125), B32(126), B32(127),
 B32(128), B32(129), B32(130), B32(131),
 B32(132), B32(133), B32(134), B32(135),
 B32(136), B32(137), B32(138), B32(139),
 B32(140), B32(141), B32(142), B32(143),
 B32(144), B32(145), B32(146), B32(147),
 B32(148), B32(149), B32(150), B32(151),
 B32(152), B32(153), B32(154), B32(155),
 B32(156), B32(157), B32(158), B32(159),
 B32(160), B32(161), B32(162), B32(163),
 B32(164), B32(165), B32(166), B32(167),
 B32(168), B32(169), B32(170), B32(171),
 B32(172), B32(173), B32(174), B32(175),
 B32(176), B32(177), B32(178), B32(179),
 B32(180), B32(181), B32(182), B32(183),
 B32(184), B32(185), B32(186), B32(187),
 B32(188), B32(189), B32(190), B32(191),
 B32(192), B32(193), B32(194), B32(195),
 B32(196), B32(197), B32(198), B32(199),
 B32(200), B32(201), B32(202), B32(203),
 B32(204), B32(205), B32(206), B32(207),
 B32(208), B32(209), B32(210), B32(211),
 B32(212), B32(213), B32(214), B32(215),
 B32(216), B32(217), B32(218), B32(219),
 B32(220), B32(221), B32(222), B32(223),
 B32(224), B32(225), B32(226), B32(227),
 B32(228), B32(229), B32(230), B32(231),
 B32(232), B32(233), B32(234), B32(235),
 B32(236), B32(237), B32(238), B32(239),
 B32(240), B32(241), B32(242), B32(243),
 B32(244), B32(245), B32(246), B32(247),
 B32(248), B32(249), B32(250), B32(251),
 B32(252), B32(253), B32(254), B32(255)
};

static const int8_t b64[256] = {
  B64(0), B64(1), B64(2), B64(3),
  B64(4), B64(5), B64(6), B64(7),
  B64(8), B64(9), B64(10), B64(11),
  B64(12), B64(13), B64(14), B64(15),
  B64(16), B64(17), B64(18), B64(19),
  B64(20), B64(21), B64(22), B64(23),
  B64(24), B64(25), B64(26), B64(27),
  B64(28), B64(29), B64(30), B64(31),
  B64(32), B64(33), B64(34), B64(35),
  B64(36), B64(37), B64(38), B64(39),
  B64(40), B64(41), B64(42), B64(43),
  B64(44), B64(45), B64(46), B64(47),
  B64(48), B64(49), B64(50), B64(51),
  B64(52), B64(53), B64(54), B64(55),
  B64(56), B64(57), B64(58), B64(59),
  B64(60), B64(61), B64(62), B64(63),
  B64(64), B64(65), B64(66), B64(67),
  B64(68), B64(69), B64(70), B64(71),
  B64(72), B64(73), B64(74), B64(75),
  B64(76), B64(77), B64(78), B64(79),
  B64(80), B64(81), B64(82), B64(83),
  B64(84), B64(85), B64(86), B64(87),
  B64(88), B64(89), B64(90), B64(91),
  B64(92), B64(93), B64(94), B64(95),
  B64(96), B64(97), B64(98), B64(99),
  B64(100), B64(101), B64(102), B64(103),
  B64(104), B64(105), B64(106), B64(107),
  B64(108), B64(109), B64(110), B64(111),
  B64(112), B64(113), B64(114), B64(115),
  B64(116), B64(117), B64(118), B64(119),
  B64(120), B64(121), B64(122), B64(123),
  B64(124), B64(125), B64(126), B64(127),
  B64(128), B64(129), B64(130), B64(131),
  B64(132), B64(133), B64(134), B64(135),
  B64(136), B64(137), B64(138), B64(139),
  B64(140), B64(141), B64(142), B64(143),
  B64(144), B64(145), B64(146), B64(147),
  B64(148), B64(149), B64(150), B64(151),
  B64(152), B64(153), B64(154), B64(155),
  B64(156), B64(157), B64(158), B64(159),
  B64(160), B64(161), B64(162), B64(163),
  B64(164), B64(165), B64(166), B64(167),
  B64(168), B64(169), B64(170), B64(171),
  B64(172), B64(173), B64(174), B64(175),
  B64(176), B64(177), B64(178), B64(179),
  B64(180), B64(181), B64(182), B64(183),
  B64(184), B64(185), B64(186), B64(187),
  B64(188), B64(189), B64(190), B64(191),
  B64(192), B64(193), B64(194), B64(195),
  B64(196), B64(197), B64(198), B64(199),
  B64(200), B64(201), B64(202), B64(203),
  B64(204), B64(205), B64(206), B64(207),
  B64(208), B64(209), B64(210), B64(211),
  B64(212), B64(213), B64(214), B64(215),
  B64(216), B64(217), B64(218), B64(219),
  B64(220), B64(221), B64(222), B64(223),
  B64(224), B64(225), B64(226), B64(227),
  B64(228), B64(229), B64(230), B64(231),
  B64(232), B64(233), B64(234), B64(235),
  B64(236), B64(237), B64(238), B64(239),
  B64(240), B64(241), B64(242), B64(243),
  B64(244), B64(245), B64(246), B64(247),
  B64(248), B64(249), B64(250), B64(251),
  B64(252), B64(253), B64(254), B64(255)
};

#if UCHAR_MAX == 255
# define uchar_in_range(c) true
#else
# define uchar_in_range(c) ((c) <= 255)
#endif

bool fnIsBase64(int8_t ch)
{
	return uchar_in_range(fnToUchar(ch)) && 0 <= b64[fnToUchar(ch)];
}

bool fnIsBase32(int8_t ch)
{
	return uchar_in_range(fnToUchar(ch)) && 0 <= b32[fnToUchar(ch)];
}

bool fnIsBase16(int8_t ch)
{
	return uchar_in_range(fnToUchar(ch)) && 0 <= b16[fnToUchar(ch)];
}

bool fnBase16Decode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	size_t outleft = outlen;
	int8_t temp;

	while (inlen >= 2)
	{
		if (!fnIsBase16(in[0]) || !fnIsBase16(in[1]))
			break;

		if (outleft)
		{
			temp = ((b16[fnToUchar(in[0])] << 4)
				| (b16[fnToUchar(in[1])] & 0x0f));
			*out++ = ((b16[fnToUchar(in[0])] << 4)
				| (b16[fnToUchar(in[1])] & 0x0f));
			outleft--;
		}

		in += 2;
		inlen -= 2;
	}

	outlen -= outleft;

	if (inlen != 0)
		return false;

	return true;
}

bool fnBase32Decode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	size_t outleft = outlen;
	int8_t temp;

	while (inlen >= 2)
	{
		if (!fnIsBase32(in[0]) || !fnIsBase32(in[1]))
			break;

		if (outleft)
		{
			temp = ((b32[fnToUchar(in[0])] << 3)
				| (b32[fnToUchar(in[1])] >> 2) & 0x07);
			*out++ = ((b32[fnToUchar(in[0])] << 3)
				| (b32[fnToUchar(in[1])] >> 2) & 0x07);
			outleft--;
		}

		if (inlen == 2)
			break;

		if (in[2] == '=')
		{
			if (inlen != 8)
				break;

			if (in[3] != '=')
				break;

		}
		else
		{
			if (!fnIsBase32(in[2]) || !fnIsBase32(in[3]))
				break;

			if (outleft)
			{
				temp = (((b32[fnToUchar(in[1])] << 6) & 0xc0)
					| (b32[fnToUchar(in[2])] << 1) | (b32[fnToUchar(in[3])] >> 4) & 0x01);
				*out++ = (((b32[fnToUchar(in[1])] << 6) & 0xc0)
					| (b32[fnToUchar(in[2])] << 1) | (b32[fnToUchar(in[3])] >> 4 ) & 0x01);
				outleft--;
			}

			if (inlen == 3)
				break;

			if (in[3] == '=')
			{
				if (inlen != 8)
					break;
			}
			else
			{
				if (!fnIsBase32(in[4]))
					break;

				if (outleft)
				{
					temp = (((b32[fnToUchar(in[3])] << 4) & 0xf0)
						| (b32[fnToUchar(in[4])] >> 1));
					*out++ = (((b32[fnToUchar(in[3])] << 4) & 0xf0)
						| (b32[fnToUchar(in[4])] >> 1));
					outleft--;
				}

				if (inlen == 4)
					break;

				if (in[4] == '=')
				{
					if (inlen != 8)
						break;

					if (in[5] != '=')
						break;

				}
				else {
					if (outleft)
					{
						if (!fnIsBase32(in[5]) || !fnIsBase32(in[6]))
							break;

						temp = (((b32[fnToUchar(in[4])] << 7) & 0x80)
							| ((b32[fnToUchar(in[5])] << 2) & 0x7c) | (b32[fnToUchar(in[6])] >> 3) & 0x03);
						*out++ = (((b32[fnToUchar(in[4])] << 7) & 0x80)
							| ((b32[fnToUchar(in[5])] << 2) & 0x7c) | (b32[fnToUchar(in[6])] >> 3) & 0x03);
						outleft--;

						if (inlen == 5)
							break;

						if (in[7] == '=')
						{
							if (inlen != 8)
								break;
						}
						else {
							if (!fnIsBase32(in[7]))
								break;

							temp = ((b32[fnToUchar(in[6])] << 5) & 0xe0)
								| ((b32[fnToUchar(in[7])]) & 0x1f);
							*out++ = ((b32[fnToUchar(in[6])] << 5) & 0xe0)
								| ((b32[fnToUchar(in[7])]) & 0x1f);
							outleft--;
						}
					}
				}
			}
		}

		in += 8;
		inlen -= 8;
	}

	outlen -= outleft;

	if (inlen != 0)
		return false;

	return true;
}

bool fnBase64Decode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen)
{
	size_t outleft = outlen;

	while (inlen >= 2)
	{
		if (!fnIsBase64(in[0]) || !fnIsBase64(in[1]))
			break;

		if (outleft)
		{
			*out++ = ((b64[fnToUchar(in[0])] << 2)
				| (b64[fnToUchar(in[1])] >> 4));
			outleft--;
		}

		if (inlen == 2)
			break;

		if (in[2] == '=')
		{
			if (inlen != 4)
				break;

			if (in[3] != '=')
				break;

		}
		else
		{
			if (!fnIsBase64(in[2]))
				break;

			if (outleft)
			{
				*out++ = (((b64[fnToUchar(in[1])] << 4) & 0xf0)
					| (b64[fnToUchar(in[2])] >> 2));
				outleft--;
			}

			if (inlen == 3)
				break;

			if (in[3] == '=')
			{
				if (inlen != 4)
					break;
			}
			else
			{
				if (!fnIsBase64(in[3]))
					break;

				if (outleft)
				{
					*out++ = (((b64[fnToUchar(in[2])] << 6) & 0xc0)
						| b64[fnToUchar(in[3])]);
					outleft--;
				}
			}
		}

		in += 4;
		inlen -= 4;
	}

	outlen -= outleft;

	if (inlen != 0)
		return false;

	return true;
}

void* fnBase64DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t needlen = 1 + BASE64_LENGTH_DECODE(inl);

	out = malloc(needlen);
	memset(out, 0, needlen);
	if (!out)
		return true;

	*inlen = inl;
	*outlen = needlen;

	return out;
}

void* fnBase32DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t needlen = 1 + BASE32_LENGTH_DECODE(inl);

	out = malloc(needlen);
	memset(out, 0, needlen);
	if (!out)
		return true;

	*inlen = inl;
	*outlen = needlen;

	return out;
}

void* fnBase16DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen)
{
	size_t inl = strlen(in);
	int8_t* out = NULL;
	size_t needlen = 1 + BASE16_LENGTH_DECODE(inl);

	out = malloc(needlen);
	memset(out, 0, needlen);
	if (!out)
		return true;

	*inlen = inl;
	*outlen = needlen;

	return out;
}