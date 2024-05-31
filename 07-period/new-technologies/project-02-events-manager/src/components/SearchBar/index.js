import Icon from "react-native-vector-icons/Octicons";
import { AppTheme } from "../../App.theme";
import { AppTextInput } from "../AppTextInput";

export function SearchBar({ onSearch }) {
  return (
    <AppTextInput
      textInputProps={{
        placeholder: "Pesquise eventos por nome ou localidade",
      }}
      suffix={<Icon name="search" color={AppTheme.placeholder} size={18} />}
      onChange={(text) => onSearch(text)}
    />
  );
}
