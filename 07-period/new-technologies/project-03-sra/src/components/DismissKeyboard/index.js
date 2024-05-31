import { Keyboard, TouchableWithoutFeedback } from "react-native";

export function DismissKeyboard({ children }) {
  return (
    <TouchableWithoutFeedback onPress={Keyboard.dismiss} accessible={false}>
      {children}
    </TouchableWithoutFeedback>
  );
}
