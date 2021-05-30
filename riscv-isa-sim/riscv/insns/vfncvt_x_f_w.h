// vfncvt.x.f.w vd, vs2, vm
VI_VFP_CVT_SCALE
({
  auto vs2 = P.VU.elt<float32_t>(rs2_num, i);
  P.VU.elt<int16_t>(rd_num, i, true) = f32_to_i16(vs2, STATE.frm, true);
},
{
  auto vs2 = P.VU.elt<float64_t>(rs2_num, i);
  P.VU.elt<int32_t>(rd_num, i, true) = f64_to_i32(vs2, STATE.frm, true);
}, false)
