#include "long_number.hpp"

using biv::LongNumber;
		
LongNumber::LongNumber() {
	// TODO
}

LongNumber::LongNumber(const char* const str) {
	// TODO
}

LongNumber::LongNumber(const LongNumber& x) {
	// TODO
}

LongNumber::LongNumber(LongNumber&& x) {
	// TODO
}

LongNumber::~LongNumber() {
	// TODO
}

LongNumber& LongNumber::operator = (const char* const str) {
	// TODO
}

LongNumber& LongNumber::operator = (const LongNumber& x {
	// TODO
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	// TODO
}

bool LongNumber::operator == (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator != (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator > (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator < (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
}

int LongNumber::get_digits_number() const noexcept {
	// TODO
}

int LongNumber::get_rank_number(int rank) const {
	// TODO
}

bool LongNumber::is_negative() const noexcept {
	// TODO
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	// TODO
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace biv {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		// TODO
	}
}
