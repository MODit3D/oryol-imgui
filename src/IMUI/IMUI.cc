//------------------------------------------------------------------------------
//  IMUI.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "IMUI.h"
#include "Core/Assertion.h"
#include "Core/Memory/Memory.h"

namespace Oryol {

IMUI::_state* IMUI::state = nullptr;

//------------------------------------------------------------------------------
void
IMUI::Setup(const IMUISetup& setup) {
    o_assert_dbg(!IsValid());
    state = Memory::New<_state>();
    state->imguiWrapper.Setup(setup);
}

//------------------------------------------------------------------------------
void
IMUI::Discard() {
    o_assert_dbg(IsValid());
    state->imguiWrapper.Discard();
    Memory::Delete(state);
    state = nullptr;
}

//------------------------------------------------------------------------------
ImFont*
IMUI::Font(int index) {
    o_assert_dbg(IsValid());
    return state->imguiWrapper.fonts[index];
}

//------------------------------------------------------------------------------
void
IMUI::NewFrame(Duration frameDuration) {
    o_assert_dbg(IsValid());
    state->imguiWrapper.NewFrame((float)frameDuration.AsSeconds());
}

//------------------------------------------------------------------------------
void
IMUI::NewFrame() {
    o_assert_dbg(IsValid());
    state->imguiWrapper.NewFrame(1.0f / 60.0f);
}

//------------------------------------------------------------------------------
void
IMUI::Render() {
    o_assert_dbg(IsValid());
    ImGui::Render();
    state->imguiWrapper.imguiRenderDrawLists(ImGui::GetDrawData());
}

//------------------------------------------------------------------------------
ImTextureID
IMUI::AllocImage() {
    o_assert_dbg(IsValid());
    return state->imguiWrapper.AllocImage();
}

//------------------------------------------------------------------------------
void
IMUI::FreeImage(ImTextureID img) {
    o_assert_dbg(IsValid());
    state->imguiWrapper.FreeImage(img);
}

//------------------------------------------------------------------------------
void
IMUI::BindImage(ImTextureID img, Id texId) {
    o_assert_dbg(IsValid());
    state->imguiWrapper.BindImage(img, texId);
}

} // namespace Oryol
