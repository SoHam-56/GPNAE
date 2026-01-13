// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae_multiply_32.h"

VL_ATTR_COLD void VTB_gpnae_multiply_32___ctor_var_reset(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___ctor_var_reset\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13254468488862703655ull);
    vlSelf->valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 550966959580451262ull);
    vlSelf->A = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3969090544990846983ull);
    vlSelf->B = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 149303876845869574ull);
    vlSelf->Result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9792351497816924968ull);
    vlSelf->done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13948340918712020156ull);
    vlSelf->__PVT__A_Mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2295616228248859173ull);
    vlSelf->__PVT__B_Mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9620425386014056888ull);
    vlSelf->__PVT__A_Exponent = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9781619203609145672ull);
    vlSelf->__PVT__B_Exponent = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 828246988963200338ull);
    vlSelf->__PVT__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11405983793283811459ull);
    vlSelf->__PVT__sign_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12635016686791530340ull);
    vlSelf->__PVT__sign_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11789220664467437120ull);
    vlSelf->__PVT__Temp_Exponent = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11047188225998844335ull);
    vlSelf->__PVT__Temp_Mantissa = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12048278941101053458ull);
    vlSelf->__PVT__intermediateMan = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14118721803911381240ull);
    vlSelf->__PVT__ManChoice1 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14894575056884060395ull);
    vlSelf->__PVT__ManChoice2 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13285449049789690336ull);
    vlSelf->__PVT__intermediateExp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14264218124275334039ull);
    vlSelf->__PVT__ExpChoice1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13828667699861636309ull);
    vlSelf->__PVT__ExpChoice2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7701106600703590494ull);
    vlSelf->__PVT__intermediateSign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14348006679363491204ull);
    vlSelf->__PVT__signChoice = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10304692949869390609ull);
    vlSelf->__PVT__choice = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17243827379129204463ull);
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__PVT__valid_stage[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12034864912165281791ull);
    }
    vlSelf->__PVT__capture_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17260411992460354636ull);
    vlSelf->__PVT__A_Exponent_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2958419979108924462ull);
    vlSelf->__PVT__B_Exponent_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14400932321796119173ull);
    vlSelf->__PVT__lowest_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8124792422936426076ull);
    vlSelf->__PVT__second_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3461595347114146126ull);
    vlSelf->__PVT__third_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16024553642139334703ull);
    vlSelf->__PVT__final_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13374845541306194138ull);
    vlSelf->__PVT__lowest_sum = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10691916715493243529ull);
    vlSelf->__PVT__second_sum = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17011470640244626584ull);
    vlSelf->__PVT__third_sum = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7341114554046760990ull);
    vlSelf->__PVT__final_sum = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13354178947317565415ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__pipe_sign[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15503477671846199477ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__pipe_Exponent[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2927154433880472782ull);
    }
    vlSelf->__PVT__unnamedblk2__DOT__i = 0;
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
    vlSelf->__PVT__unnamedblk3__DOT__i = 0;
    vlSelf->__Vlvbound_h673e5fa3__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10764140225552219440ull);
    vlSelf->__Vlvbound_h13242171__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3500757513832711094ull);
    vlSelf->__Vlvbound_h2883e456__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2992285853669992786ull);
    vlSelf->__PVT__karatsuba__DOT__A_high = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 331278703365304931ull);
    vlSelf->__PVT__karatsuba__DOT__A_low = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4034965422219321140ull);
    vlSelf->__PVT__karatsuba__DOT__B_high = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15704402129336272089ull);
    vlSelf->__PVT__karatsuba__DOT__B_low = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 3055423913378012664ull);
    vlSelf->__PVT__karatsuba__DOT__P_low_raw = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11702712238219134885ull);
    vlSelf->__PVT__karatsuba__DOT__P_high_raw = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7051087683143350681ull);
    vlSelf->__PVT__karatsuba__DOT__P_middle = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 17179430630275693023ull);
    vlSelf->__PVT__karatsuba__DOT__temp1 = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 18046968695438263816ull);
    vlSelf->__PVT__karatsuba__DOT__temp2 = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 8317848190827369884ull);
    vlSelf->__PVT__karatsuba__DOT__P_high = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17807411915999059795ull);
    vlSelf->__PVT__karatsuba__DOT__P_low = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7232720449833834451ull);
    vlSelf->__PVT__karatsuba__DOT__temp3_stage1 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 3806634800274018822ull);
    vlSelf->__PVT__karatsuba__DOT__P_low2 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 8246851255751792588ull);
    vlSelf->__PVT__karatsuba__DOT__temp3 = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6653899242247331997ull);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4575767142982613437ull);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted1 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2465619761872521747ull);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted2 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17362898033029205162ull);
    vlSelf->__PVT__karatsuba__DOT__temp3_shifted = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4557183215749820656ull);
    vlSelf->__PVT__karatsuba__DOT__partial_product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6081450764928476233ull);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14361107363040880111ull);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended1 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 956638009732644236ull);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended2 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10957791227197857133ull);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17342954493084958358ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2643827993388761362ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12796331617870675766ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__val[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8381769672703380269ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13622394442077238675ull);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17138815832417356414ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15672159800600775774ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11490423992514474225ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__accum = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11629299056867420070ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15092535394718653704ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1551815799725967502ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4995573342826394804ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 527563434466528443ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4591494530713770939ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4020941033556868173ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7130598477501098919ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h18691515__0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9809191994338995800ull);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h55a11ffb__0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11583110058984452574ull);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8271393512419447352ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13377785895079095364ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6775468365724937647ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__val[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12014150611004633656ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2335395876113139553ull);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 780415796950990742ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15905732571754859034ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4691160702833731379ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__accum = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4847590175422055524ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17205743514084631652ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13726854749338151194ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 100661333018045514ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5242744114952117454ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11922710385468880063ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4989697184367253341ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 84241518248583146ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h18691515__0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9649599212191694015ull);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h55a11ffb__0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4907812576711981483ull);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[__Vi0] = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 17798481862478966963ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[__Vi0] = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 14345308619169860236ull);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11575380099040593527ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__val[__Vi0] = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 9941381935624550143ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[__Vi0] = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 4033311412476962930ull);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 11725067043601846399ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 6123883462718936090ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 708313007484035948ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__accum = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 11424418968901080471ull);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7579780309730806887ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 13907257575794528453ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 6277978048156690799ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 11899965250844540406ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 3157207765495873897ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 13974672311567698100ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 5231914826219043670ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h08726fad__0 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 16405175547061529371ull);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h40082228__0 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 18438041725902754731ull);
    vlSelf->__VdlyVal__valid_stage__v0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8245815820119628019ull);
    vlSelf->__VdlySet__valid_stage__v0 = 0;
    vlSelf->__VdlyVal__valid_stage__v1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2777471086658834719ull);
    vlSelf->__VdlySet__valid_stage__v1 = 0;
    vlSelf->__VdlyVal__valid_stage__v2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16885294112837203870ull);
    vlSelf->__VdlySet__valid_stage__v2 = 0;
    vlSelf->__VdlyVal__valid_stage__v3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6889530454697513003ull);
    vlSelf->__VdlySet__valid_stage__v3 = 0;
    vlSelf->__VdlyVal__valid_stage__v4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14075418690203947901ull);
    vlSelf->__VdlySet__valid_stage__v4 = 0;
    vlSelf->__VdlyVal__valid_stage__v5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14812414066798647953ull);
    vlSelf->__VdlySet__valid_stage__v5 = 0;
    vlSelf->__VdlyVal__valid_stage__v6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17539881124515055519ull);
    vlSelf->__VdlySet__valid_stage__v6 = 0;
    vlSelf->__VdlySet__valid_stage__v7 = 0;
    vlSelf->__VdlyVal__valid_stage__v12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8520853190441403113ull);
    vlSelf->__VdlySet__valid_stage__v12 = 0;
    vlSelf->__VdlyVal__valid_stage__v13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10029698525819227603ull);
    vlSelf->__VdlySet__valid_stage__v14 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2160399779305424830ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11279800581408164271ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15565998525827158440ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15623105059827510420ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2789275848796288797ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14801429901740273979ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6325884570043560098ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6503511260298772547ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18438625099119140813ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4277513556883388493ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15862306692905905611ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1385047623140159093ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18039968821032008717ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2254086615745922807ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 16506659474253394182ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 11531309649781155786ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 17069870151948811011ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 7849429067088706161ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 3760792711001215021ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 1675156971728274559ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 16497131323124082813ull);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__pipe_sign__v0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4179761166633961348ull);
    vlSelf->__VdlySet__pipe_sign__v0 = 0;
    vlSelf->__VdlyVal__pipe_sign__v1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6570496810290632928ull);
    vlSelf->__VdlySet__pipe_sign__v1 = 0;
    vlSelf->__VdlyVal__pipe_sign__v2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17884597813271304041ull);
    vlSelf->__VdlySet__pipe_sign__v2 = 0;
    vlSelf->__VdlyVal__pipe_sign__v3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4096087527636630455ull);
    vlSelf->__VdlySet__pipe_sign__v3 = 0;
    vlSelf->__VdlyVal__pipe_sign__v4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6900089011393837414ull);
    vlSelf->__VdlySet__pipe_sign__v4 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7546597565051708071ull);
    vlSelf->__VdlySet__pipe_Exponent__v0 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13227693815292712910ull);
    vlSelf->__VdlySet__pipe_Exponent__v1 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2592348611809818052ull);
    vlSelf->__VdlySet__pipe_Exponent__v2 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10117674028045859741ull);
    vlSelf->__VdlySet__pipe_Exponent__v3 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v4 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2743740709746277827ull);
    vlSelf->__VdlySet__pipe_Exponent__v4 = 0;
}
