/**********************************************************************************************************************
 * Copyright (c) Prophesee S.A.                                                                                       *
 *                                                                                                                    *
 * Licensed under the Apache License, Version 2.0 (the "License");                                                    *
 * you may not use this file except in compliance with the License.                                                   *
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0                                 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed   *
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                      *
 * See the License for the specific language governing permissions and limitations under the License.                 *
 **********************************************************************************************************************/

#ifndef METAVISION_SDK_STREAM_FRAME_DIFF_H
#define METAVISION_SDK_STREAM_FRAME_DIFF_H

#include <memory>
#include <functional>

// Metavision SDK Base Frame Diff
#include "metavision/sdk/base/events/raw_event_frame_diff.h"

// Definition of CallbackId
#include "metavision/sdk/base/utils/callback_id.h"

namespace Metavision {

/// @brief Type alias for a callback on a @ref RawEventFrameDiff
using RawEventFrameDiffCallback = std::function<void(const RawEventFrameDiff &d)>;

/// @brief Facility class to handle RawEventFrameDiff
class FrameDiff {
public:
    /// @brief Destructor
    ///
    /// Deletes a FrameDiff class instance.
    virtual ~FrameDiff();

    /// @brief Subscribes to FrameDiff events
    ///
    /// Registers a callback that will be called each time a RawEventFrameDiff has been decoded.
    ///
    /// @param cb Callback to call each time a RawEventFrameDiff has been decoded
    /// @sa @ref RawEventFrameDiffCallback
    /// @return ID of the added callback
    CallbackId add_callback(const RawEventFrameDiffCallback &cb);

    /// @brief Removes a previously registered callback
    /// @param callback_id Callback ID
    /// @return true if the callback has been unregistered correctly, false otherwise.
    /// @sa @ref add_callback
    bool remove_callback(CallbackId callback_id);

    /// @brief For internal use
    class Private;
    /// @brief For internal use
    Private &get_pimpl();

private:
    FrameDiff(Private *);
    std::unique_ptr<Private> pimpl_;
};

} // namespace Metavision

#endif // METAVISION_SDK_STREAM_FRAME_DIFF_H
