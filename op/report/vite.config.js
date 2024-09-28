import react from '@vitejs/plugin-react'
import { resolve } from 'path'
import { defineConfig } from 'vite'

// https://vitejs.dev/config/
export default defineConfig({
	plugins: [react()],
	build: {
		manifest: true,
		historyApiFallback: true,
		rollupOptions: {
			input: {
				main: resolve(__dirname, 'index.html'),
				katalog: resolve(__dirname, 'pages/LabsKatalog/LabsKatalog.jsx'),
			},
		},
	},
})
