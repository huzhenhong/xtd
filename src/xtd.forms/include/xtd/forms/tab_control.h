/// @file
/// @brief Contains xtd::forms::tab_control container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "image_list.h"
#include "tab_alignment.h"
#include "tab_page_ref.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Manages a related set of tab pages.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html containers_tab_control_w.png</td>
    ///     <td>@image html containers_tab_control_m.png</td>
    ///     <td>@image html containers_tab_control_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <td>Dark</td>
    ///     <td>@image html containers_tab_control_wd.png</td>
    ///     <td>@image html containers_tab_control_md.png</td>
    ///     <td>@image html containers_tab_control_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of tab_control container.
    /// @include tab_control.cpp
    class forms_export_ tab_control : public control {
      struct data;
      
    public:
      /// @brief Represents a collection of controls.
      class tab_page_collection : public xtd::forms::layout::arranged_element_collection<tab_page_ref> {
      public:
        /// @name Alias
        
        /// @{
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<tab_page_ref>;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::control::tab_page_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit tab_page_collection(const allocator_type& allocator = allocator_type());
        /// @}
        
        /// @cond
        explicit tab_page_collection(const base& collection);
        tab_page_collection(const tab_page_collection& collection);
        tab_page_collection& operator =(const tab_page_collection& collection);
        tab_page_collection(tab_page_collection&&) = default;
        /// @endcond
        
        /// @name Methods
        
        /// @{
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::insert;
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param text The text of element to insert.
        iterator insert(const_iterator pos, const xtd::ustring& text);
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param text The text of element to insert.
        /// @param name The name of element to insert.
        iterator insert(const_iterator pos, const xtd::ustring& text, const xtd::ustring& name);
        
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::insert_at;
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        void insert_at(size_t index, const xtd::ustring& text);
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        /// @param name The name of element to insert.
        void insert_at(size_t index, const xtd::ustring& text, const xtd::ustring& name);
        
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::push_back;
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        void push_back(const xtd::ustring& text);
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        /// @param name The name of element to add.
        void push_back(const xtd::ustring& text, const ustring& name);
        
        /// @}
        
        /// @cond
        void push_back(const char* text);
        void push_back(const char8* text);
        void push_back(const char16* text);
        void push_back(const char32* text);
        void push_back(const wchar* text);
        /// @endcond
        
        /// @name Operators
        
        /// @{
        using base::operator [];
        /// @brief Gets the first xtd::forms::control::tab_page_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator [](const xtd::ustring& name) const;
        /// @brief Gets the first xtd::forms::control::tab_page_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator [](const xtd::ustring& name);
        /// @}
      private:
        friend tab_control;
        event<tab_page_collection, delegate<void(size_t index, const ustring& text, const ustring& name)>> text_added;
        event<tab_page_collection, delegate<iterator(const_iterator pos, const ustring& text, const ustring& name)>> text_inserted;
      };
      
      /// @name Fields
      
      /// @{
      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the tab_control class.
      tab_control();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the area of the control (for example, along the top) where the tabs are aligned.
      /// @return One of the xtd::forms::tab_alignment values. The default is top.
      virtual tab_alignment alignment() const noexcept;
      /// @brief Sets the area of the control (for example, along the top) where the tabs are aligned.
      /// @param alignment One of the xtd::forms::tab_alignment values. The default is top.
      /// @return Current tab_control instance.
      virtual tab_control& alignment(tab_alignment alignment);
      
      /// @brief Gets the images to display on the control's tabs.
      /// @return An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual const forms::image_list& image_list() const noexcept;
      /*
      /// @brief Gets the images to display on the control's tabs.
      /// @return An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual forms::image_list& image_list() {return image_list_;}
       */
      /// @brief Sets the images to display on the control's tabs.
      /// @param value An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @return Current tab_control instance.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual tab_control& image_list(const forms::image_list& value);
      
      /// @brief Gets the index of the currently selected tab page.
      /// @return The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      virtual size_t selected_index() const noexcept;
      /// @brief Sets the index of the currently selected tab page.
      /// @param selected_index The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      /// @return Current tab_control instance.
      virtual tab_control& selected_index(size_t selected_index);
      
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A tab_page_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      virtual tab_page_collection& tab_pages() noexcept;
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A tab_page_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      virtual const tab_page_collection& tab_pages() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::tab_control with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::tab_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @param name The name of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      static tab_control create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::tab_control with specified parent, text, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::tab_control.
      /// @param text A string that represent text of the xtd::forms::tab_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @param name The name of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      static tab_control create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the selected_index property has changed.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<tab_control, event_handler> selected_index_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      
      void on_control_added(const control_event_args& e) override;
      void on_control_removed(const control_event_args& e) override;
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Raises the tab_control::selected_index_changed event.
      /// @param An xtd::event_args that contains the event data.
      virtual void on_selected_index_changed(const event_args& e);
      
      void wnd_proc(message& message) override;
      /// @}
      
      /// @cond
      friend class tab_page;
      size_t get_child_index(intptr page);
      /// @endcond
      
    private:
      friend class xtd::forms::form;
      using control::controls;
      
      void on_tab_pages_item_added(size_t, control_ref item);
      void on_tab_pages_item_removed(size_t, control_ref item);
      void on_tab_pages_text_added(size_t index, const ustring& text, const ustring& name);
      tab_page_collection::iterator on_tab_pages_text_inserted(tab_page_collection::const_iterator pos, const ustring& text, const ustring& name);
      
      void wm_command_control(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
