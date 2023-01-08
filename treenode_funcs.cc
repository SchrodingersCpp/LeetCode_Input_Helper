#include "treenode_funcs.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

#include "num_string_funcs.h"

std::size_t LongestStrVal(
    const std::vector<std::vector<std::string>>& vec_lvl) {
  std::size_t len_max{};
  for (const std::vector<std::string>& lvl_row : vec_lvl) {
    for (const std::string& str_val : lvl_row) {
      len_max = std::max(len_max, str_val.size());
    }
  }
  return len_max;
}

void FormatTreeNodeStrVals(
    std::vector<std::vector<std::string>>& vec_lvl, const std::size_t width) {
  for (std::vector<std::string>& lvl_row : vec_lvl) {
    for (std::string& str_val : lvl_row) {
      CenterStr(str_val, width);
    }
  }
}

void GrowInitBranches(std::vector<std::vector<std::string>>& vec_lvl) {
  const char brch_char{ '_' };  // Branch char.
  for (std::size_t i_lvl{}; i_lvl < (vec_lvl.size() - 1); ++i_lvl) {
    for (std::string& str_val : vec_lvl[i_lvl]) {
      if (!IsCenteredStrEmpty(str_val)) {
        std::replace(str_val.begin(), str_val.end(), ' ', brch_char);
      }
    }
  }
}

void FormatData(
    std::vector<std::size_t>& dist_to_l_elem,
    std::vector<std::size_t>& dist_btw_elems,
    std::vector<std::size_t>& brch_width,
    const std::vector<std::vector<std::string>>& vec_lvl,
    const std::size_t min_dist) {
  const std::size_t n_lvls{ vec_lvl.size() };
  const std::size_t elem_len{ vec_lvl[0][0].size() };
  std::vector<std::size_t> pair_width(n_lvls);  // Width of a pair of elems.
  pair_width.back() = elem_len;
  dist_to_l_elem.back() = 0;
  dist_btw_elems.back() = min_dist;
  brch_width.back() = 0;
  for (std::size_t i{ n_lvls - 2 }; i < n_lvls; --i) {
    pair_width[i] = 2 * pair_width[i+1] + min_dist;
    dist_to_l_elem[i] = (pair_width[i] - elem_len) / 2;
    dist_btw_elems[i] = pair_width[i] - elem_len + min_dist;
    brch_width[i] = dist_to_l_elem[i] - (dist_to_l_elem[i+1] + elem_len / 2);
  }
}

std::vector<std::string> FormatTreeNodeLvls(
    const std::vector<std::vector<std::string>>& vec_lvl,
    const std::size_t min_dist/*=1*/) {
  const char brch_char{ '_' };  // Branch char.
  const char space_char{ ' ' };  // Spacing char.
  const std::size_t n_lvls{ vec_lvl.size() };
  const std::size_t elem_len{ vec_lvl[0][0].size() };
  std::vector<std::string> vec_fmt_lvl(n_lvls);  // Formatted lines.
  std::vector<std::size_t> dist_to_l_elem(n_lvls);  // Spacing to first elem.
  std::vector<std::size_t> dist_btw_elems(n_lvls);  // Spacing btw neighbors.
  std::vector<std::size_t> brch_width(n_lvls);  // Length of an elem branch.
  FormatData(
      dist_to_l_elem, dist_btw_elems, brch_width,
      vec_lvl, min_dist);
  for (std::size_t i_lvl{}; i_lvl < n_lvls; ++i_lvl) {
    const std::size_t n_elems{ vec_lvl[i_lvl].size() };
    const std::string spacing(
        dist_btw_elems[i_lvl] - 2 * brch_width[i_lvl], space_char);
    std::string& fmt_lvl{ vec_fmt_lvl[i_lvl] };
    const std::size_t n_left_spaces{ dist_to_l_elem[i_lvl] - brch_width[i_lvl] };
    fmt_lvl = std::string(n_left_spaces, space_char);
    for (std::size_t i_elem{}; i_elem < n_elems; ++i_elem) {
      char branch_char{ brch_char };
      if (IsCenteredStrEmpty(vec_lvl[i_lvl][i_elem])) {
        branch_char = space_char;
      }
      const std::string branch(brch_width[i_lvl], branch_char);
      fmt_lvl += branch + vec_lvl[i_lvl][i_elem] + branch;
      if (i_elem != (n_elems - 1)) {
        fmt_lvl += spacing;
      }
    }
  }
  return vec_fmt_lvl;
}
