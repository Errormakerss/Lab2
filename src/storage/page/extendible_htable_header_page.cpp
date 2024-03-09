//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// extendible_htable_header_page.cpp
//
// Identification: src/storage/page/extendible_htable_header_page.cpp
//
// Copyright (c) 2015-2023, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "storage/page/extendible_htable_header_page.h"

#include "common/exception.h"

namespace bustub {

void ExtendibleHTableHeaderPage::Init(uint32_t max_depth) {
  max_depth_ = max_depth;
  std::fill(directory_page_ids_, directory_page_ids_ + HTABLE_HEADER_ARRAY_SIZE, INVALID_PAGE_ID);
  // clear dictionary //
  //  this->directory_page_ids_.
  //  throw NotImplementedException("ExtendibleHTableHeaderPage is not implemented");
}
auto ExtendibleHTableHeaderPage::HashToDirectoryIndex(uint32_t hash) const -> uint32_t {
  //  max_depth_ = 1;
  if (max_depth_ == 0) return 0;
  return hash >> (32 - max_depth_);
}

auto ExtendibleHTableHeaderPage::GetDirectoryPageId(uint32_t directory_idx) const -> uint32_t {
  return directory_page_ids_[directory_idx];
}

void ExtendibleHTableHeaderPage::SetDirectoryPageId(uint32_t directory_idx, page_id_t directory_page_id) {
  directory_page_ids_[directory_idx] = directory_page_id;
}
auto ExtendibleHTableHeaderPage::MaxSize() const -> uint32_t {
  return std::min(HTABLE_HEADER_ARRAY_SIZE, static_cast<uint64_t>(1 << max_depth_));
}

}  // namespace bustub
