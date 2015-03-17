/** @file
    @brief Header

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_InterfaceTree_h_GUID_7F88FD57_3657_4AA6_B725_A1C69AA21ED2
#define INCLUDED_InterfaceTree_h_GUID_7F88FD57_3657_4AA6_B725_A1C69AA21ED2

// Internal Includes
#include <osvr/Client/ClientInterfacePtr.h>
#include <osvr/Util/TreeNode.h>

// Library/third-party includes
// - none

// Standard includes
#include <vector>

namespace osvr {
namespace client {
    /// @brief Holds on to lists of interfaces organized into the tree
    /// structure.
    class InterfaceTree {
      public:
        typedef std::vector<ClientInterfacePtr> value_type;
        typedef util::TreeNode<value_type> node_type;
        /// @brief Constructor
        InterfaceTree();

        /// @brief Add an interface to the tree.
        ///
        /// @returns true if this is the first interface for that path.
        bool addInterface(ClientInterfacePtr const &iface);

        /// @brief Remove an interface from the tree.
        ///
        /// @returns true if that path no longer has any interfaces.
        bool removeInterface(ClientInterfacePtr const &iface);

        /// @brief Returns a reference to the list of interfaces registered for
        /// a given path.
        value_type &getInterfacesForPath(std::string const &path);

        /// @brief Returns a reference to a node for a given path.
        node_type &getNodeForPath(std::string const &path);

      private:
        node_type::ptr_type m_root;
    };

} // namespace client
} // namespace osvr
#endif // INCLUDED_InterfaceTree_h_GUID_7F88FD57_3657_4AA6_B725_A1C69AA21ED2
